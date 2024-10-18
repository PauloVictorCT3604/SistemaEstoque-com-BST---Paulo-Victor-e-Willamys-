#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do produto como um nó da árvore binária de busca (BST)
typedef struct produto {
    char nome[50];
    int cod;
    int quant;
    float preco;
    struct produto* esquerda; // Subárvore esquerda
    struct produto* direita;  // Subárvore direita
} produto;

// Função para criar um novo nó (produto) na árvore
produto* novoProduto(char* nome, int cod, int quant, float preco) {
    produto* novo = (produto*)malloc(sizeof(produto));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->cod = cod;
    novo->quant = quant;
    novo->preco = preco;
    novo->esquerda = novo->direita = NULL; // Inicializa os filhos como NULL
    return novo;
}

// Função para inserir um novo produto na BST (de forma ordenada pelo código)
produto* inserirProduto(produto* raiz, char* nome, int cod, int quant, float preco) {
    if (raiz == NULL) {
        return novoProduto(nome, cod, quant, preco); // Inserção do nó na posição correta
    }
    if (cod < raiz->cod) {
        raiz->esquerda = inserirProduto(raiz->esquerda, nome, cod, quant, preco);
    } else if (cod > raiz->cod) {
        raiz->direita = inserirProduto(raiz->direita, nome, cod, quant, preco);
    } else {
        printf("Codigo %d ja existe!\n", cod);
    }
    return raiz;
}

// Função para buscar um produto na BST pelo código (Busca Binária)
produto* buscarProduto(produto* raiz, int cod) {
    if (raiz == NULL || raiz->cod == cod) {
        return raiz; // Se raiz for NULL ou encontramos o produto, retornamos o nó
    }
    if (cod < raiz->cod) {
        return buscarProduto(raiz->esquerda, cod); // Busca à esquerda
    }
    return buscarProduto(raiz->direita, cod); // Busca à direita
}

// Função para imprimir um produto
void imprimirProduto(produto* p) {
    if (p != NULL) {
        printf("Produto encontrado:\n Codigo: %d - Nome: %s - Quantidade: %d - Preco: %.2f\n",p->cod , p->nome, p->quant, p->preco);
    } else {
        printf("Produto nao encontrado!\n");
    }
}

// Função para imprimir todos os produtos em ordem crescente (in-ordem)
void imprimirProdutosEmOrdem(produto* raiz) {
    if (raiz != NULL) {
        imprimirProdutosEmOrdem(raiz->esquerda);
        printf("Nome: %s | Codigo: %d | Quantidade: %d | Preco: %.2f\n", raiz->nome, raiz->cod, raiz->quant, raiz->preco);
        imprimirProdutosEmOrdem(raiz->direita);
    }
}

// Função para encontrar o nó com o menor valor (sucessor in-order)
produto* encontrarMinimo(produto* node) {
    produto* atual = node;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

// Função para deletar um produto da árvore BST pelo código
produto* deletarProduto(produto* raiz, int cod) {
    if (raiz == NULL) {
        printf("Produto com codigo %d nao encontrado!\\n", cod);
        return raiz;
    }

    // Se o código a ser deletado for menor, está na subárvore esquerda
    if (cod < raiz->cod) {
        raiz->esquerda = deletarProduto(raiz->esquerda, cod);
    }
    // Se o código for maior, está na subárvore direita
    else if (cod > raiz->cod) {
        raiz->direita = deletarProduto(raiz->direita, cod);
    }
    // Achou o produto com o código
    else {
        // Caso 1: Nó sem filhos (nó folha)
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);  // Libera a memória
            return NULL;
        }
        // Caso 2: Nó com apenas um filho
        else if (raiz->esquerda == NULL) {
            produto* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            produto* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: Nó com dois filhos
        produto* temp = encontrarMinimo(raiz->direita);  // Encontra o sucessor in-order
        raiz->cod = temp->cod;
        strncpy(raiz->nome, temp->nome, sizeof(raiz->nome) - 1);
        raiz->quant = temp->quant;
        raiz->preco = temp->preco;

        // Deleta o sucessor
        raiz->direita = deletarProduto(raiz->direita, temp->cod);
    }
    return raiz;
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n=======================\n");
    printf("  Sistema de Estoque  \n");
    printf("=======================\n");
    printf("Escolha uma opcao:\n");
    printf("1. Inserir produto\n");
    printf("2. Buscar produto\n");
    printf("3. Imprimir todos os produtos\n");
    printf("4. Deletar produto\n");
    printf("5. Sair\n");
    printf("=======================\n");
}

int main() {
    produto* estoque = NULL; // Raiz da árvore começa vazia
    int escolha, cod, quant;
    float preco;
    char nome[50];

    do {
    exibirMenu();
        printf("Sua Escolha: ");
        scanf("%d", &escolha);
        printf("=======================\n");

        switch (escolha) {
            case 1:
                printf("Nome do produto: ");
                scanf(" %[^\n]%*c", nome);
                printf("Codigo do produto: ");
                scanf("%d", &cod);
                printf("Quantidade: ");
                scanf("%d", &quant);
                printf("Preco: ");
                scanf("%f", &preco);
                estoque = inserirProduto(estoque, nome, cod, quant, preco);
                break;
            
            case 2:
                printf("Codigo do produto a ser buscado: ");
                scanf("%d", &cod);
            case 3:
                printf("Produtos no estoque:\n");
                imprimirProdutosEmOrdem(estoque);
                break;

            case 4:    
                printf("Codigo do produto a ser removido:");
                scanf ("%d", &cod);
                estoque = deletarProduto(estoque, cod);
                printf("Produto deletado com sucesso\n");
                break;

            case 5:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (escolha != 5);

    return 0;
}

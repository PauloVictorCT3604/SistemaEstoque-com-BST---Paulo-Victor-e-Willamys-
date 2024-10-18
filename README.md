# Sistema de Estoque com Árvore Binária de Busca (BST)

Este projeto implementa um sistema de gerenciamento de estoque utilizando a técnica de Árvore Binária de Busca (BST). O programa permite a inserção, busca, listagem e remoção de produtos, cada um identificado por um código único. As operações de busca e inserção são otimizadas pela estrutura de árvore, garantindo eficiência.

## Funcionalidades

- **Inserir Produto:** Adiciona um novo produto ao estoque. A inserção é feita de maneira ordenada com base no código do produto, utilizando a técnica de Árvore Binária de Busca.
- **Buscar Produto:** Permite a busca por um produto específico utilizando o código como chave, aplicando o algoritmo de busca binária.
- **Listar Produtos:** Exibe todos os produtos do estoque em ordem crescente de código, utilizando o percurso in-order da BST.
- **Remover Produto:** Remove um produto do estoque com base no código fornecido, ajustando a árvore conforme necessário.
  
## Estrutura de Dados

### Definição do Nó (Produto)

Cada produto é representado por um nó na árvore BST, contendo as seguintes informações:

- `nome`: Nome do produto.
- `cod`: Código único do produto (utilizado para manter a ordem na árvore).
- `quant`: Quantidade disponível no estoque.
- `preco`: Preço do produto.
- `esquerda`: Ponteiro para o filho à esquerda (nós com código menor).
- `direita`: Ponteiro para o filho à direita (nós com código maior).

### Operações com a BST

#### Inserção de Produtos

A função `inserirProduto` insere um novo produto na árvore de forma ordenada, comparando o código do novo produto com os códigos já existentes na árvore. Essa operação garante que a árvore mantenha sua propriedade de BST, onde os nós à esquerda possuem códigos menores e os da direita, maiores.

#### Busca de Produtos

A função `buscarProduto` utiliza a técnica de **Busca Binária** para localizar um produto na árvore com base no código. Esse algoritmo segue o princípio de dividir a busca pela metade, explorando a subárvore esquerda ou direita dependendo do valor do código buscado, tornando a busca eficiente.

#### Listagem de Produtos

A listagem de produtos é feita utilizando um percurso **in-order** na árvore, que visita os nós na ordem crescente de seus códigos. A função `imprimirProdutosEmOrdem` realiza esse percurso, garantindo que os produtos sejam exibidos de forma organizada.

#### Remoção de Produtos

A função `deletarProduto` remove um nó (produto) da árvore BST. Existem três cenários principais na remoção:
1. O nó é uma folha (sem filhos).
2. O nó tem um único filho.
3. O nó tem dois filhos: nesse caso, o sucessor in-order (nó com o menor valor da subárvore à direita) substitui o nó removido.

## Como Executar

1. Clone este repositório ou copie o código.
2. Compile o código utilizando um compilador C:
   ``bash``

## Idealizadores 

- Paulo Victor Bezerra Brito
- Willamys Carneiro
   gcc -o sistema_estoque sistema_estoque.c

## Link Apresentação em Slides

[Abrir design no Canva](https://www.canva.com/design/DAGTyoeA5gE/-sGXZl1cvdbF3OT1OTGvxA/edit?utm_content=DAGTyoeA5gE&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)


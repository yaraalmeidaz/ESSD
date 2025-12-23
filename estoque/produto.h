#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Funções do estoque
void inicializarEstoque();
void liberarEstoque();

void cadastrarProdutos();
void exibirInfo();
void adicionarItens();
void removerItens();
void calcularTotal();

#endif

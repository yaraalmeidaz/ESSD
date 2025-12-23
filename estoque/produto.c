#include <stdio.h>
#include <stdlib.h> // p poder usar malloc,realloc e free
#include <string.h> // p poder usar strcpy copiar uma string para dentro de outra.
//e strcmp comparar duas strings.
#include "produto.h"

static Produto* estoque = NULL;
static int tamanho = 0;
/*
static serve p isolar variveis, ou seja 
só as funções de produto.c podem acessar estoque e tamanho
 
estoque é uma varivel *Produto (um ponteiro p ser usado em Produto)
e definindo que que o estoque sera armazenado em ponteiro ao inves de:
//Produto estoque[100];

Isso reserva 100 produtos para sempre, mesmo que você cadastre só 2.
Ou seja, memória desperdiçada.
 */
void inicializarEstoque() {
    estoque = NULL;
    tamanho = 0;
}

void liberarEstoque() {
    free(estoque);
    estoque = NULL;
    tamanho = 0;
}

void cadastrarProdutos(){
        Produto novo;

    printf("Digite o ID do produto: ");
    scanf("%d", &novo.id);
    while(getchar() != '\n'); // Limpa o buffer após scanf

    printf("Digite o nome do produto: ");
    fgets(novo.nome, 50, stdin);

    // Remove o \n no final, se existir
    size_t len = strlen(novo.nome);
    if(len > 0 && novo.nome[len-1] == '\n') {
        novo.nome[len-1] = '\0';
    }
    
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &novo.preco);

    Produto* temp = realloc(estoque, (tamanho + 1) * sizeof(Produto));
    /*
    ponteiro_novo = realloc(ponteiro_original, novo_tamanho_em_bytes);
     */
    if( temp == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    estoque = temp;
    estoque [tamanho] = novo;
    tamanho++;

    printf("Produto cadastrado com sucesso!\n");
}

void exibirInfo(){
    if(tamanho == 0){
        printf("Nenhum produto foi cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    for(int i = 0; i < tamanho; i++){
        printf("ID: %d | Nome: %s | Quantidade: %d | Preço: %.2f\n",
               estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}

void adicionarItens(){
    int id, qtd;
    printf("Digite o ID do produto:");
    scanf("%d", &id);

    printf("Digite a quantidade a adicionar: ");
    scanf("%d", &qtd);

    for(int i = 0; i < tamanho; i++){
        if(estoque[i].id == id){
           estoque[i].quantidade += qtd;
            printf("Quantidade atualizada! Agora tem %d unidades.\n", estoque[i].quantidade);
            return;
        }
    }
    printf("Produto não encontrado!\n");

}

void removerItens(){
    int id, qtd;

    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    printf("Digite a quantidade a remover: ");
    scanf("%d", &qtd);

    for(int i = 0; i < tamanho; i++){
        if(estoque[i].id == id){ // Primeiro encontra o produto
            if(estoque[i].quantidade >= qtd){ // Depois verifica quantidade
                estoque[i].quantidade -= qtd;
                printf("Remoção feita! Agora tem %d unidades.\n", estoque[i].quantidade);
            } else {
                printf("Quantidade insulficiente no estoque! \n");
            }
            return;
        }
    }
    printf("Produto não foi encontrado!\n");
}


void calcularTotal(){
    float total = 0;
    
    for(int i = 0; i < tamanho; i++){
        total += (estoque[i].preco * estoque[i].quantidade);
    }
    printf("Valor total do estoque: R$ %.2f\n", total);

}

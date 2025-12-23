#include <stdio.h>
#include "produto.h"

int main(){
    int opcao;

    inicializarEstoque();// Inicializa a memória

    do{
        printf("--- Menu de gerenciamento de Produtos ---\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Exibir informações do produto\n");
        printf("3. Adicionar itens ao estoque\n");
        printf("4. Remover itens do estoque\n");
        printf("5. Calcular valor total do estoque\n");
        printf("6. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while(getchar() != '\n'); // limpa buffer



        switch(opcao){
            case 1: cadastrarProdutos(); break; 
            case 2: exibirInfo(); break;
            case 3: adicionarItens(); break;
            case 4: removerItens();break;
            case 5: calcularTotal();break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opção inválida! Tente novamente.\n"); break;

        } 
    }while(opcao != 6);

    liberarEstoque();
    return 0;
    
}
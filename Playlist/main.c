#include <stdio.h>
#include "musica.h"

int main(){
    int opcao;

    inicializarPlaylist();// Inicializa a memória

    do{
        printf("--- Playlist ---\n");
        printf("1. Adicionar uma nova música:\n");
        printf("2. Exibir a playlist completa\n");
        printf("3. Atualizar uma música\n");
        printf("4. Exibir o total de músicas e duração da playlist\n");
        printf("5. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while(getchar() != '\n'); // limpa buffer


        switch(opcao){
            case 1: adicionarMusica(); break; 
            case 2: exibirInfo(); break;
            case 3: atualizarMusica(); break;
            case 4: quantidadeMusica();break;
            case 5: printf("Saindo...\n"); break;
            default: printf("Opção inválida! Tente novamente.\n"); break;

        } 
    }while(opcao != 5);

    liberarMemoria();
    return 0;
    
}


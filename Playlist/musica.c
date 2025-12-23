#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h>
#include "musica.h"

Musica* head = NULL; // início da lista

void inicializarPlaylist() {
    head = NULL;
}

void adicionarMusica(){
    Musica* nova = malloc(sizeof(Musica)); //aloca(tamanho de Musica)
    /*
    // Aloca espaço para um vetor de 10 inteiros
    int *vetor;
    vetor = malloc(10 * sizeof(int)); 
    Aloca 10 * 4 bytes (se int for 4 bytes)
     */
    if (nova == NULL){ //ou  if(!nova)
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o titulo: ");
    //fgets(destino, tamanho, origem);
    //origem → de onde ler, normalmente stdin (entrada do teclado).
    fgets(nova->titulo, 100, stdin);
    nova->titulo[strcspn(nova->titulo, "\n")] = '\0';

    /*

    nome[strcspn(nome, "\n")] = '\0';

    strcspn(nome, "\n") → procura a posição do primeiro \n na string.
    Substituímos ele por \0 (fim da string).
    Assim "yara almeida\n" vira "yara almeida".

    fgets guarda o \n (Enter) junto com o texto
    
    *
    operador -> faz a "mesma coisa" do (.)
    mas o -> é quando você tem um ponteiro para struct.
    Musica* nova

    */

    printf("Digite o artista: ");
    fgets(nova->artista, 100, stdin);
    nova->artista[strcspn(nova->artista, "\n")] = '\0';

    printf("Digite a duração em segundos: ");
    scanf("%d", &nova->duracao_segundos);
    getchar(); // consome o '\n' que sobrou no buffer

    nova->proximo = NULL; //+ nó p lista, q no caso por esta em NULL indica q ate agr é o ultimo
    
    if(head == NULL){ // se caso head == NULL indica que esta inicilizando
        head = nova; //head passa a ser nova
    } else {
        Musica* atual = head; 
        /*
        ponteiro atual do tipo Musica q começa apontando p head, 
        ou seja inicio da lisra
        */
        while( atual->proximo != NULL){
            atual = atual->proximo;
        }

        atual->proximo = nova; //head → [Musica1 | prox] → [Musica2 | prox] → NULL
                
    }

}

void exibirInfo() {
    Musica* atual = head;
    if (atual == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    printf("\n--- Playlist ---\n");
    while (atual != NULL) {
        printf("Título: %s | Artista: %s | Duração: %d segundos\n",
               atual->titulo, atual->artista, atual->duracao_segundos);
        atual = atual->proximo;
    }
}


void atualizarMusica(){
    char tituloBusca[100];
    printf("Digite o titulo da musica: ");
    //fgets(destino, tamanho, origem);
    //nome[strcspn(nome, "\n")] = '\0';

    fgets(tituloBusca, 100, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';


    Musica* atual = head;
    while (atual != NULL) {
        if (strcmp(atual->titulo, tituloBusca) == 0) {
            printf("Novo título: ");
            fgets(atual->titulo, 100, stdin);
            atual->titulo[strcspn(atual->titulo, "\n")] = '\0';

            printf("Novo artista: ");
            fgets(atual->artista, 100, stdin);
            atual->artista[strcspn(atual->artista, "\n")] = '\0';

            printf("Nova duração em segundos: ");
            scanf("%d", &atual->duracao_segundos);
            getchar(); // limpar buffer

            printf("Música atualizada com sucesso!\n");
            return;
        }
        atual = atual->proximo;
    }

    printf("Música não encontrada.\n");
}

void quantidadeMusica(){

    if(head == NULL){
        printf("playlist vazia.\n");
        return;
    }

    int totalDeMusicas = 0;
    int totalDeSegundos = 0;

    Musica* atual = head;
    while(atual != NULL){
        totalDeMusicas++;
        totalDeSegundos += atual->duracao_segundos;

        atual = atual->proximo;
    }

    printf("Total de músicas: %d\n", totalDeMusicas);
    printf("Duração total: %d segundos\n", totalDeSegundos);

}

void liberarMemoria() {
    Musica* atual = head;
    while (atual != NULL) {
        Musica* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head = NULL;
}

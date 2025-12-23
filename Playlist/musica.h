#ifndef MUSICA_H
#define MUSICA_H

typedef struct Musica{
    char titulo[100];
    char artista[100];
    int duracao_segundos;
    struct Musica* proximo; // ponteiro autorreferênciado p prox ponto do no
} Musica;

//funcoes
void inicializarPlaylist();
void liberarMemoria();

void adicionarMusica();
void exibirInfo();
void atualizarMusica();
void quantidadeMusica();
    
#endif

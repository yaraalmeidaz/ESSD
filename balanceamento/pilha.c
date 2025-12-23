#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Cria uma pilha dinâmica
Pilha* criarPilha(int capacidade){ 
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->capacidade = capacidade;
    p->topo = -1;
    p->itens = (char*) malloc(capacidade * sizeof(char));
    return p;
}

// funcao vai verifica se ta vazia
int isEmpty(Pilha *p){
    return p->topo == -1;
}

// verifica se ta cheio
int isFull(Pilha *p){
    return p->topo == p->capacidade - 1;
}

// empilha (push)
void push(Pilha *p, char valor){
    if (isFull(p)) {
        printf("Erro: pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = valor;
}

// desempilha (pop)
char pop(Pilha *p){
    if (isEmpty(p)) {
        return '\0';
    }
    return p->itens[p->topo--];
}

// consulta o topo (peek)
char topo(Pilha *p){
    if (isEmpty(p)) return '\0';
    return p->itens[p->topo];
}

// libera memória
void liberarPilha(Pilha *p){
    free(p->itens);
    free(p);
}

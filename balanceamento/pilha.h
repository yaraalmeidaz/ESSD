#ifndef PILHA_H
#define PILHA_H

#define MAX 100

//estrutura da pilha
typedef struct {
    char *itens;
    int topo;
    int capacidade;
} Pilha;

//protótipos das funções
Pilha* criarPilha(int capacidade);
int isEmpty(Pilha *p);
int isFull(Pilha *p);
void push(Pilha *p, char valor);
char pop(Pilha *p);
char topo(Pilha *p);
void liberarPilha(Pilha *p);

#endif

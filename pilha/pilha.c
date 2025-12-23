#include <stdio.h>
#include <stdlib.h>

/* Definindo a estrutura que representará cada elemento da pilha */
/* O typedef permite usar "PILHA" em vez de "struct pilha" */
typedef struct pilha {
    int num;
    struct pilha *prox;
} PILHA;

int main(void) {
    /* O ponteiro topo aponta para o elemento no topo da pilha. */
    /* Começa com NULL porque a pilha está vazia. */
    PILHA *topo = NULL;
    PILHA *aux; /* Ponteiro auxiliar */
    int op;

    do {
        /* Limpa a tela (funciona no Windows) */
        /* Para Linux/macOS, use system("clear"); */
        system("clear");

        printf("\nMENU DE OPCOES\n");
        printf("\n1 - Inserir na pilha");
        printf("\n2 - Consultar toda a pilha");
        printf("\n3 - Remover da pilha");
        printf("\n4 - Esvaziar a pilha");
        printf("\n5 - Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 5) {
            printf("Opcao invalida!!");
        }

        if (op == 1) {
            printf("Digite o numero a ser inserido na pilha: ");
            PILHA *novo = (PILHA *) malloc(sizeof(PILHA));
            scanf("%d", &novo->num);
            novo->prox = topo;
            topo = novo;
            printf("Numero inserido na pilha!!");
        }

        if (op == 2) {
            if (topo == NULL) {
                /* A pilha está vazia */
                printf("Pilha vazia!!");
            } else {
                /* A pilha contém elementos */
                printf("\nConsultando toda a pilha\n");
                aux = topo;
                while (aux != NULL) {
                    printf("%d ", aux->num);
                    aux = aux->prox;
                }
            }
        }

        if (op == 3) {
            if (topo == NULL) {
                /* A pilha está vazia */
                printf("Pilha vazia!!");
            } else {
                /* Remove o último elemento inserido */
                aux = topo;
                printf("Numero %d removido", topo->num);
                topo = topo->prox;
                free(aux);
            }
        }

        if (op == 4) {
            if (topo == NULL) {
                /* A pilha está vazia */
                printf("Pilha vazia!!");
            } else {
                /* A pilha será esvaziada */
                aux = topo;
                while (aux != NULL) {
                    topo = topo->prox;
                    free(aux);
                    aux = topo;
                }
                printf("Pilha esvaziada");
            }
        }
        
        /* Pausa para o usuário ver a mensagem antes de limpar a tela */
        printf("\n\nPressione Enter para continuar...");
        getchar(); /* Consome o '\n' deixado pelo scanf */
        getchar(); /* Espera o usuário pressionar Enter */

    } while (op != 5);
    
    return 0;
}
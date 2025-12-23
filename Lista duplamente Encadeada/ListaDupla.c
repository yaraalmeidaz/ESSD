//tipo de daados do tipo Lista
//funções q manipula a Lista
#include <stdio.h>
#include "ListaDupla.h"

struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    struct aluno dados;
};

//variavel criada para facilitar a manipulação
typedef struct elemento Elem;


Lista *li; //ponteiro p ponteiro


//apos criar a lista
Lista* cria_lista(){ 
    //li vai ser o ponteiro q vai armazenar a memoria
    //li é um ponteiro para ponteiro (por isso Lista* li)
    //*li acessa o conteúdo apontado por li

    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
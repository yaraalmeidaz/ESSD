#include <stdio.h>

    int main(){
        
        int valor = 100;
        int *p_valor;

        p_valor = &valor;

        printf("Valor antes da mudança: %d\n", valor); //100

        //usando o ponteiro para mudar a variavel valor
        *p_valor = 200;

        printf("Valor depois da mudança: %d\n", valor); //200
        printf("Valor acessado pelo ponteiro: %d\n", *p_valor); //200


        //isso foi feito com Operador de Desreferência (*)

    return 0;
    }

//NULL p inicializar ponteiros pq dessa forma vc tem controle de onde ele esta apontado
//pq tem especificar o tipo de variavel p ponteirp?
//dessa forma ele sabe a qnt de bytes para procurar (a memoria varia entre char, int, float)
#include <stdio.h>

void dobra_valores(int *vetor, int tamanho);

int main(){
    int numeros[] = {1,2,3,4,5};
    int tamanho = 5;
    
    printf("Valores originais d vetor:\n");
    for(int i = 0; i <tamanho; i++){
        printf("%d, ", numeros[i]);
    }
    printf("\n");

    //passa vetor por referencia
    //vetor meio q ja é ponteiro por isso n precina "sinalizar"
    dobra_valores(numeros, tamanho);
    printf("Valores apos a funçõ d vetor:\n");
    for(int i = 0; i <tamanho; i++){
        printf("%d, ", numeros[i]);
    }
    printf("\n");
    return 0;
}

void dobra_valores(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = vetor[i] * 2;
    }
}
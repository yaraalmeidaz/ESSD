#include <stdio.h>

void troca_valores(int *ptr_a, int *ptr_b);

int main(){
    int a = 10, b = 50;

    printf("Valores antes da troca a = %d, b = %d\n", a,b);

    //cham a função
    troca_valores(&a, &b);

    printf("valores dps da troca a = %d, b = %d\n", a, b);

    return 0;
}


void troca_valores(int *ptr_a, int *ptr_b){
    //varaivel temporararia apenas pra fzr a troca
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}
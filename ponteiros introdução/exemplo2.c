#include <stdio.h>
int main(){

    int numero = 50;
    int *ponteiro_numero;

    // ponteiro numero aponta para numero
    //Operador de Endereço (&):
    ponteiro_numero = &numero;

    printf("Valor da variavel 'numero': %d\n", numero);
    //varaivel valor p e usa o & para mostra endereço
    //Operador de Endereço (&):
    printf("Endereço da variavel 'numero': %p\n", &numero);
    printf("Valor do ponteiro 'ponteiro_numero' (endereço): %p\n", ponteiro_numero);
    //Operador de Desreferência (*)
    printf("Valor acessado pelo ponteiro (*ponteiro_numero): %d\n", *ponteiro_numero);


return 0;
}
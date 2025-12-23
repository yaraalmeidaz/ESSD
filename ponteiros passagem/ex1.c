#include <stdio.h>

void dobrar_e_triplicar(int num_valor, int *ptr_num_referencia);

int main(void){
    int numA, numB;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numA);
    printf("Digite o segundo numero: ");
    scanf("%d", &numB);

    printf("Antes da função: numA = %d, numB = %d\n", numA, numB);
    //somente o segundo numero deve ser passado por referenciq(ponteiro)
    //por isso o &numB ---> & para indicar endereço de variavel
    dobrar_e_triplicar(numA, &numB);
    printf("Depois da função: numA = %d, numB = %d\n", numA, numB);

    return 0;
}
//num_valor = numA e numB = *ptr_num_referencia 
//como as varaiveis estão cada uma em seu tipo, int e ponteiro, faz a associação direta

void dobrar_e_triplicar(int num_valor, int *ptr_num_referencia){
    num_valor = num_valor * 2;
    //dentro da função pq a varivel foi feira nessa escopo
    printf("Dobro do primeiro numero (apenas dentro da função): %d\n", num_valor);

        //referencia muda indenpendet por ser mudança de endereço
    *ptr_num_referencia = *ptr_num_referencia * 3;
    printf("Triplo do segundo numero (modificado fora da função): %d\n", *ptr_num_referencia);
}


/*A passagem por valor é sempre o caminho mais seguro mas nem sempre 
é o caminho mais simples, na mainupalção de arrays ou strings por exemplo*/
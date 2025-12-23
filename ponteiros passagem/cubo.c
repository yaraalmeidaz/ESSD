#include <stdio.h>

//int CuboPorValor(int n);
void CuboPorReferencia(int *nPtr);


int main(void){
    int numero = 5;
    printf("O valor original é %d", numero);

    //numero = CuboPorReferencia(numero);
    CuboPorReferencia(&numero);

    printf("O novo valor do numero é %d\n", numero);

    return 0;
}

//int CuboPorValor (int n){
//  return n*n*n;
//}
void CuboPorReferencia(int *nPtr){

    *nPtr = *nPtr * *nPtr * *nPtr;
}
#include <stdio.h>
#include <string.h>
#include "pilha.h"

// fncaoo auxiliar para verificar se os símbolos correspondem
int correspondem(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

// funcao  de verificação
int verificarBalanceamento(char *expressao) {
    Pilha *p = criarPilha(MAX); //cria uma nova pilha para armazenar os smbolos
    int i;
    char c, topoChar;

    //percorre td a expressao ate \0
    for (i = 0; expressao[i] != '\0'; i++) {
        c = expressao[i];
        if (c == '(' || c == '[' || c == '{') {
            push(p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(p)) {
                liberarPilha(p);
                return 0;
            }
            topoChar = pop(p);
            if (!correspondem(topoChar, c)) {
                liberarPilha(p);
                return 0;
            }
        }
    }

    int balanceada = isEmpty(p);
    liberarPilha(p);
    return balanceada;
}

//  principal
int main() {
    char expressao[MAX];

    printf("Digite uma expressao: ");
    fgets(expressao, MAX, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    if (verificarBalanceamento(expressao))
        printf("Expressao: %s\n--> Balanceada \n", expressao);
    else
        printf("Expressao: %s\n--> Nao Balanceada \n", expressao);

    return 0;
}

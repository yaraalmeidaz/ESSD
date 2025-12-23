//Evidenciei a parte do bubble sort e insert sort 
//atraves dos comentaários


#include <stdio.h>

int main(){

    int vetorA[5], vetorB[5];
    int i, rodada, temp, pos, escolhido;
    int contBubble, contInsert;

    // lendo os números e copiando para o segundo vetor
    for(i = 0; i < 5; i++)
    {
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &vetorA[i]);
        vetorB[i] = vetorA[i]; // copia para usar no Insert Sort
    }

    // BUBBLE SORT ordenando por trocas
    contBubble = 0;
    for(rodada = 1; rodada <= 5; rodada++)
    {
        for(i = 0; i < 4; i++)
        {
            // compara números vizinhos
            if(vetorA[i] > vetorA[i+1])
            {
                // troca
                temp = vetorA[i];
                vetorA[i] = vetorA[i+1];
                vetorA[i+1] = temp;
            }
            contBubble++;
        }
    }

    // mostrando o resultado do buble
    printf("\nBubble Sort: %d comparacoes\n", contBubble);
    for(i = 0; i < 5; i++)
    {
        printf("%dº numero: %d\n", i+1, vetorA[i]);
    }

    // INSERT SORT ordena inserindo na posição correta
    contInsert = 0;
    for(i = 1; i < 5; i++)
    {
        escolhido = vetorB[i]; // valor que será colocado na posição certa
        pos = i - 1;

        // encaminha os maiores para a direita
        while(pos >= 0 && vetorB[pos] > escolhido)
        {
            vetorB[pos+1] = vetorB[pos];
            pos--;
            contInsert++;
        }

        // coloca o num no lugar certo
        vetorB[pos+1] = escolhido;
    }

    // mostra o resultado do Insert Sort
    printf("\nInsert Sort: %d movimentos\n", contInsert);
    for(i = 0; i < 5; i++)
    {
        printf("%dº numero: %d\n", i+1, vetorB[i]);
    }

    return 0;
}

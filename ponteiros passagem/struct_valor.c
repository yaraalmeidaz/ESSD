#include <stdio.h>
#include <string.h>

//definicção de struct
typedef struct{
    char nome[50];
    int idade;
} Pessoa;

void altera_pessoa_por_valor(Pessoa p){
    printf("Alterando dentro da função(por valor)...\n");
    p.idade = 30;
    printf("Idadde dntro da função: %d", p.idade);
}

int main(){
    Pessoa minha_pessoa;
    strcpy(minha_pessoa.nome, "Maria");
    minha_pessoa.idade = 25;

    printf("Idade original: %d\n", minha_pessoa);

    altera_pessoa_por_valor(minha_pessoa);
    printf("idade apos a função: %d", minha_pessoa.idade);
    
    return 0;
}
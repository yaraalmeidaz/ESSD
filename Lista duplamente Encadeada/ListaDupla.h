//prototipo das funções 
//tipo de dado
//ponteiro lista --> ponteiro apontando p ponteiro

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};



//ponteiro elemento do tipo Lista
typedef struct elemento* Lista; 

//Criar uma lista
Lista* cria_lista();



/* Fig. 12.3: fig12_03.c
   Operando e mantendo uma lista */
#include <stdio.h>
#include <stdlib.h> /* para malloc e free */

/* estrutura autorreferenciada */
struct listNode {
    char data; /* cada listNode contém um caractere */
    struct listNode *nextPtr; /* ponteiro para próximo nó */
}; /* fim da estrutura listNode */

typedef struct listNode ListNode; /* sinônimo de struct listNode */
typedef ListNode *ListNodePtr; /* sinônimo de ListNode */

/* protótipos */
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );

int main( void )
{
    ListNodePtr startPtr = NULL; /* inicialmente não existem nós */
    int choice; /* escolha do usuário */
    char item; /* char inserido pelo usuário */

    system("clear");


    instructions(); /* exibe o menu */
    printf( "? " );
    scanf( "%d", &choice );

    /* loop enquanto usuário não escolhe 3 */
    while ( choice != 3 ) {

        switch ( choice ) {
            case 1:
                printf( "\n--- Operação: Inserir ---\n" );
                printf( "Digite um caractere para inserir: " );
                scanf( "\n%c", &item );
                insert( &startPtr, item ); /* insere item na lista */
                printList( startPtr );
                break;
            case 2: /* exclui um elemento */
                printf( "\n--- Operação: Excluir ---\n" );
                /* se lista não está vazia */
                if ( !isEmpty( startPtr ) ) {
                    printf( "Digite o caractere a ser excluído: " );
                    scanf( "\n%c", &item );

                    /* se caractere for encontrado, é removido */
                    if ( delete( &startPtr, item ) ) { /* remove item */
                        printf( "  [INFO DELETE] Caractere '%c' excluído com sucesso.\n", item );
                        printList( startPtr );
                    } /* fim do if */
                    else {
                        printf( "  [INFO DELETE] Caractere '%c' não encontrado na lista.\n\n", item );
                    } /* fim do else */
                } /* fim do if */
                else {
                    printf( "  [INFO DELETE] Lista está vazia. Nada para excluir.\n\n" );
                } /* fim do else */

                break;
            default:
                printf( "Escolha inválida. Tente novamente.\n\n" );
                instructions();
                break;
        } /* fim do switch */

        printf( "? " );
        scanf( "%d", &choice );
    } /* fim do while */

    printf( "Fim da execução.\n" );
    return 0; /* indica conclusão bem-sucedida */
} /* fim do main */

/* exibe instruções do programa ao usuário */
void instructions( void )
{
    printf( "\n--- Menu ---\n" );
    printf( "Digite sua escolha:\n" );
    printf( "   1 para inserir um elemento na lista.\n" );
    printf( "   2 para excluir um elemento da lista.\n" );
    printf( "   3 para terminar o programa.\n" );
    printf( "------------\n" );
} /* fim das instruções de função */

/* Insere novo valor na lista, na ordem classificada */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr;        /* ponteiro para novo nó */
    ListNodePtr previousPtr;   /* ponteiro para nó anterior na lista */
    ListNodePtr currentPtr;    /* ponteiro para nó atual na lista */

    printf( "  [INFO INSERT] Tentando inserir o caractere: '%c'\n", value );

    printf( "  [INFO INSERT] 1. Alocando memória para o novo nó (newPtr).\n" );
    newPtr = malloc( sizeof( ListNode ) ); /* cria nó */

    if ( newPtr != NULL ) { /* espaço está disponível */
        printf( "  [INFO INSERT]    Memória alocada com sucesso para newPtr (Endereço: %p).\n", (void*)newPtr );
        newPtr->data = value; /* coloca valor no nó */
        printf( "  [INFO INSERT]    Atribuindo o valor '%c' ao campo 'data' de newPtr.\n", newPtr->data );
        newPtr->nextPtr = NULL; /* nó não se une a outro nó */
        printf( "  [INFO INSERT]    Definindo 'nextPtr' de newPtr como NULL (Endereço: %p).\n", (void*)newPtr->nextPtr );

        previousPtr = NULL;
        currentPtr = *sPtr;
        printf( "  [INFO INSERT] 2. Inicializando ponteiros de travessia.\n" );
        printf( "  [INFO INSERT]    previousPtr = NULL (Endereço: %p).\n", (void*)previousPtr );
        printf( "  [INFO INSERT]    currentPtr = *sPtr (HEAD da lista) (Endereço: %p).\n", (void*)currentPtr );


        printf( "  [INFO INSERT] 3. Percorrendo a lista para encontrar o local de inserção (mantendo ordem crescente).\n" );
        /* loop para achar o local correto na lista */
        while ( currentPtr != NULL && value > currentPtr->data ) {
            printf( "  [INFO INSERT]    currentPtr (data: '%c') é menor que '%c'. Movendo para o próximo nó.\n", currentPtr->data, value );
            previousPtr = currentPtr; /* caminha para ...*/
            currentPtr = currentPtr->nextPtr; /* ... próximo nó */
            printf( "  [INFO INSERT]    previousPtr agora aponta para %p (data: '%c').\n", (void*)previousPtr, previousPtr->data );
            printf( "  [INFO INSERT]    currentPtr agora aponta para %p.\n", (void*)currentPtr );
        } /* fim do while */
        printf( "  [INFO INSERT]    Loop de travessia finalizado.\n" );


        /* insere novo nó no início da lista */
        if ( previousPtr == NULL ) {
            printf( "  [INFO INSERT] 4. previousPtr é NULL. Inserindo no INÍCIO da lista.\n" );
            newPtr->nextPtr = *sPtr; // O novo nó aponta para o antigo início
            printf( "  [INFO INSERT]    newPtr->nextPtr (%p) agora aponta para o antigo *sPtr (%p).\n", (void*)newPtr->nextPtr, (void*)*sPtr );
            *sPtr = newPtr; // O ponteiro de início da lista (HEAD) agora aponta para o novo nó
            printf( "  [INFO INSERT]    *sPtr (HEAD) agora aponta para newPtr (%p).\n", (void*)*sPtr );
        } /* fim do if */
        else { /* insere novo nó entre previousPtr e currentPtr */
            printf( "  [INFO INSERT] 4. previousPtr NÃO é NULL. Inserindo NO MEIO/FINAL da lista.\n" );
            previousPtr->nextPtr = newPtr; // O nó anterior aponta para o novo nó
            printf( "  [INFO INSERT]    previousPtr->nextPtr (%p) agora aponta para newPtr (%p).\n", (void*)previousPtr->nextPtr, (void*)newPtr );
            newPtr->nextPtr = currentPtr; // O novo nó aponta para o nó que era o próximo do anterior
            printf( "  [INFO INSERT]    newPtr->nextPtr (%p) agora aponta para currentPtr (%p).\n", (void*)newPtr->nextPtr, (void*)currentPtr );
        } /* fim do else */
        printf( "  [INFO INSERT] Caractere '%c' inserido com sucesso na lista.\n", value );
    } /* fim do if */
    else {
        printf( "  [INFO INSERT] ERRO: %c não inserido. Sem memória disponível.\n", value );
    } /* fim do else */
    printf( "---------------------------\n" );
} /* fim da função insert */

/* Exclui um elemento da lista */
char delete( ListNodePtr *sPtr, char value )
{
    ListNodePtr previousPtr; /* ponteiro para nó anterior na lista */
    ListNodePtr currentPtr; /* ponteiro para nó atual na lista */
    ListNodePtr tempPtr; /* ponteiro de nó temporário */

    printf( "  [INFO DELETE] Tentando excluir o caractere: '%c'\n", value );

    // Adição da verificação de lista vazia para evitar segmentation fault
    if ( *sPtr == NULL ) {
        printf( "  [INFO DELETE] ERRO: Lista vazia. Não há nada para excluir.\n" );
        return '\0'; // Não há nada para excluir
    }

    printf( "  [INFO DELETE] 1. Verificando se o elemento a ser excluído é o primeiro nó (HEAD).\n" );
    /* exclui primeiro nó */
    if ( value == ( *sPtr )->data ) {
        printf( "  [INFO DELETE]    Caractere '%c' encontrado no início da lista.\n", value );
        tempPtr = *sPtr; /* aponta para o nó que está sendo removido */
        printf( "  [INFO DELETE]    tempPtr (%p) aponta para o nó a ser removido (o antigo *sPtr).\n", (void*)tempPtr );
        *sPtr = ( *sPtr )->nextPtr; /* o HEAD da lista agora aponta para o próximo nó */
        printf( "  [INFO DELETE]    *sPtr (HEAD) agora aponta para o próximo nó (%p).\n", (void*)*sPtr );
        free( tempPtr ); /* libera o nó com thread retirado */
        printf( "  [INFO DELETE]    Memória do nó %p (dado: '%c') liberada.\n", (void*)tempPtr, value );
        return value;
    } /* fim do if */
    else {
        printf( "  [INFO DELETE]    Caractere '%c' NÃO é o primeiro nó. Percorrendo a lista.\n", value );
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;
        printf( "  [INFO DELETE]    previousPtr inicializado para *sPtr (%p).\n", (void*)previousPtr );
        printf( "  [INFO DELETE]    currentPtr inicializado para (*sPtr)->nextPtr (%p).\n", (void*)currentPtr );


        printf( "  [INFO DELETE] 2. Percorrendo a lista para encontrar o nó a ser excluído.\n" );
        /* loop para achar local correto na lista */
        while ( currentPtr != NULL && currentPtr->data != value ) {
            printf( "  [INFO DELETE]    currentPtr (data: '%c') não é '%c'. Movendo para o próximo nó.\n", currentPtr->data, value );
            previousPtr = currentPtr; /* caminha até ... */
            currentPtr = currentPtr->nextPtr; /* ... próximo nó */
            printf( "  [INFO DELETE]    previousPtr agora aponta para %p (data: '%c').\n", (void*)previousPtr, previousPtr->data );
            printf( "  [INFO DELETE]    currentPtr agora aponta para %p.\n", (void*)currentPtr );
        } /* fim do while */
        printf( "  [INFO DELETE]    Loop de travessia finalizado.\n" );


        /* exclui nó em currentPtr */
        if ( currentPtr != NULL ) {
            printf( "  [INFO DELETE] 3. Caractere '%c' encontrado (no endereço %p). Excluindo do meio/fim da lista.\n", value, (void*)currentPtr );
            tempPtr = currentPtr; // Guarda o nó a ser excluído
            printf( "  [INFO DELETE]    tempPtr (%p) aponta para o nó a ser removido.\n", (void*)tempPtr );
            previousPtr->nextPtr = currentPtr->nextPtr; // O nó anterior aponta para o que vinha DEPOIS do nó excluído
            printf( "  [INFO DELETE]    previousPtr->nextPtr (%p) agora aponta para currentPtr->nextPtr (%p).\n", (void*)previousPtr->nextPtr, (void*)currentPtr->nextPtr );
            free( tempPtr ); // Libera a memória do nó
            printf( "  [INFO DELETE]    Memória do nó %p (dado: '%c') liberada.\n", (void*)tempPtr, value );
            return value;
        } /* fim do if */
    } /* fim do else */

    printf( "  [INFO DELETE] Caractere '%c' não encontrado na lista após travessia.\n", value );
    printf( "---------------------------\n" );
    return '\0'; // Caractere não encontrado
} /* fim da função delete */

/* Retorna 1 se a lista estiver vazia, 0 se estiver cheia */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* fim da função isEmpty */

/* Imprime a lista */
void printList( ListNodePtr currentPtr )
{
    printf( "--- Estado Atual da Lista ---\n" );
    /* se lista estiver vazia */
    if ( currentPtr == NULL ) {
        printf( "Lista está vazia.\n\n" );
    } /* fim do if */
    else {
        printf( "A lista é: HEAD --> " );

        /* enquanto não chega ao final da lista */
        while ( currentPtr != NULL ) {
            printf( "'%c' (%p) --> ", currentPtr->data, (void*)currentPtr );
            currentPtr = currentPtr->nextPtr;
        } /* fim do while */

        printf( "NULL\n\n" );
    } /* fim do else */
    printf( "---------------------------\n" );
} /* fim da função printList */
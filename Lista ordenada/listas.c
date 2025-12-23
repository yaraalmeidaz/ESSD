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

    instructions(); /* exibe o menu */
    printf( "? " );
    scanf( "%d", &choice );

    /* loop enquanto usuário não escolhe 3 */
    while ( choice != 3 ) {

        switch ( choice ) {
            case 1:
                printf( "Digite um caractere: " );
                scanf( "\n%c", &item );
                insert( &startPtr, item ); /* insere item na lista */
                printList( startPtr );
                break;
            case 2: /* exclui um elemento */
                /* se lista não está vazia */
                if ( !isEmpty( startPtr ) ) {
                    printf( "Digite caractere a ser excluído: " );
                    scanf( "\n%c", &item );

                    /* se caractere for encontrado, é removido */
                    if ( delete( &startPtr, item ) ) { /* remove item */
                        printf( "%c deleted.\n", item );
                        printList( startPtr );
                    } /* fim do if */
                    else {
                        printf( "%c não encontrado.\n\n", item );
                    } /* fim do else */
                } /* fim do if */
                else {
                    printf( "Lista está vazia.\n\n" );
                } /* fim do else */

                break;
            default:
                printf( "Escolha inválida.\n\n" );
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
    printf( "Digite sua escolha:\n" );
    printf( "   1 para inserir um elemento na lista.\n" );
    printf( "   2 para excluir um elemento da lista.\n" );
    printf( "   3 para terminar.\n" );
} /* fim das instruções de função */

/* Insere novo valor na lista, na ordem classificada */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr; /* ponteiro para novo nó */
    ListNodePtr previousPtr; /* ponteiro para nó anterior na lista */
    ListNodePtr currentPtr; /* ponteiro para nó atual na lista */

    newPtr = malloc( sizeof( ListNode ) ); /* cria nó */

    if ( newPtr != NULL ) { /* espaço está disponível */
        newPtr->data = value; /* coloca valor no nó */
        newPtr->nextPtr = NULL; /* nó não se une a outro nó */

        previousPtr = NULL;
        currentPtr = *sPtr;

        /* loop para achar o local correto na lista */
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr; /* caminha para ...*/
            currentPtr = currentPtr->nextPtr; /* ... próximo nó */
        } /* fim do while */

        /* insere novo nó no início da lista */
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } /* fim do if */
        else { /* insere novo nó entre previousPtr e currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* fim do else */
    } /* fim do if */
    else {
        printf( "%c não inserido. Sem memória disponível.\n", value );
    } /* fim do else */
} /* fim da função insert */

/* Exclui um elemento da lista */
char delete( ListNodePtr *sPtr, char value )
{
    ListNodePtr previousPtr; /* ponteiro para nó anterior na lista */
    ListNodePtr currentPtr; /* ponteiro para nó atual na lista */
    ListNodePtr tempPtr; /* ponteiro de nó temporário */

    // Adição da verificação de lista vazia para evitar segmentation fault
    if ( *sPtr == NULL ) {
        return '\0'; // Não há nada para excluir
    }

    /* exclui primeiro nó */
    if ( value == ( *sPtr )->data ) {
        tempPtr = *sPtr; /* aponta para o nó que está sendo removido */
        *sPtr = ( *sPtr )->nextPtr; /* retira thread do nó */
        free( tempPtr ); /* libera o nó com thread retirado */
        return value;
    } /* fim do if */
    else {
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;

        /* loop para achar local correto na lista */
        while ( currentPtr != NULL && currentPtr->data != value ) {
            previousPtr = currentPtr; /* caminha até ... */
            currentPtr = currentPtr->nextPtr; /* ... próximo nó */
        } /* fim do while */

        /* exclui nó em currentPtr */
        if ( currentPtr != NULL ) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free( tempPtr );
            return value;
        } /* fim do if */
    } /* fim do else */

    return '\0';
} /* fim da função delete */

/* Retorna 1 se a lista estiver vazia, 0 se estiver cheia */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* fim da função isEmpty */

/* Imprime a lista */
void printList( ListNodePtr currentPtr )
{
    /* se lista estiver vazia */
    if ( currentPtr == NULL ) {
        printf( "Lista está vazia.\n\n" );
    } /* fim do if */
    else {
        printf( "A lista é:\n" );

        /* enquanto não chega ao final da lista */
        while ( currentPtr != NULL ) {
            printf( "%c --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        } /* fim do while */

        printf( "NULL\n\n" );
    } /* fim do else */
} /* fim da função printList */
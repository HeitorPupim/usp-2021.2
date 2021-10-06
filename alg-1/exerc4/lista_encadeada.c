#include <lista_encadeada.h>

typedef struct No 
{
    int valor;
    struct No *proximo;
}No;

typedef struct 
{
    No *inicio, *fim;
    int tam;
}Lista;


//inserir início da lista

void insertInicio(Lista *lista, int valor)
{
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;

    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}

void InsertFim(Lista *lista, int valor)
{
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL)//lista vazia
    {
        lista->inicio = novo;
        lista->fim = novo;
    } else { //lista n vazia
        lista->fim->proximo = novo;
        lista->fim = novo; 
    }
    lista->tam++;
}

void printLista(Lista *lista)
{
    No *inicio = lista->inicio; //vai percorrrer do inicio ao fim
    printf("Tamanho da lista: %d\n", lista->tam);

    while (inicio != NULL)
    {
        printf("%d \n", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("fim da lista!\n");
}

//remover um elemento da lista
// o 2º parametro vai ser o elemento a ser removido
// remover um elemento da lista
void removerElemento(Lista *lista, int valor) {
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No * noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->valor == valor) { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a memória do nó
        lista->tam--; // decrementa o tamanho da lista
    }
}

// função que remove e retorna o primeiro nó
No* removerPrimeiroNO(Lista *lista) {
    if(lista->inicio != NULL) {
        No *no = lista->inicio;
        lista->inicio = no->proximo;
        lista->tam--;
        if(lista->inicio == NULL)
            lista->fim = NULL;
        return no;
    } else
        return NULL;
}
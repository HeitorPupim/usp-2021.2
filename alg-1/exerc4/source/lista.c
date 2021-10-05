#include <lista.h>

typedef struct no_st no_t;

struct no_st {
    num info;
    no_t *prox;
};

struct lista_st {
    no_t *ini, *fim;
    int tam;
};


// Aloca espaço para a lista e define os parâmetros iniciais.
lista_t *cria() {
    lista_t *lista = malloc(sizeof(lista_t));

    lista->tam = 0;
    lista->ini = NULL;
    lista->fim = NULL;

    return lista;
}

/* Desaloca o espaço reservado para cada nó
 * da lista e o espaço da própria lista.
 */
void destroi(lista_t *lista) {
    if (lista == NULL) return;
    no_t *p = lista->ini;
    while (p != NULL) {
        lista->ini = p->prox;
        free(p);
        p = lista->ini;
    }
    free(lista);
}

/* Aloca espaço para um nó, seta os parâmetros
 * desse nó e insere no final da lista, fazendo
 * as devidas verificações.
 * Incrementa o tamanho da lista ao inserir esse novo nó.
 */
void insere(lista_t *lista, num x) {
    if (lista == NULL) return;
    
    no_t *p = malloc(sizeof(no_t));
    p->info = x;
    p->prox = NULL;

    if (lista->ini == NULL)
        lista->ini = p;
    else
        lista->fim->prox = p;

    lista->fim = p;
    lista->tam++;
}

/* Remove um nó da lista, independentemente da posição
 * dele na lista.
 * Procura o primeiro nó que contém esse valor, libera a memória
 * reservada para ele, e diminui o tamanho da lista.
 */
void remover(lista_t *lista, num x) {
    if (lista == NULL) return;
    no_t *anterior = NULL;
    no_t *p = lista->ini;

    while (p != NULL) {
        if (p->info == x) {
            if (p == lista->ini) {
                lista->ini = lista->ini->prox;
            } else if (p == lista->fim) {
                lista->fim = anterior;
                lista->fim->prox = NULL;
            } else {
                anterior->prox = p->prox;
            }
            free(p);
            lista->tam--;
            
            return; // Se removeu
        } else {
            anterior = p;
            p = p->prox;
        }
    }
}

/* Retorna o tamanho da lista
 */
int tamanho(lista_t *lista) {
    if (lista != NULL) return lista->tam;

    return -1;
}

/* Imprime o conteúdo de todos os nós
 * da lista.
 */
void imprimir(lista_t *lista) {
    if (lista == NULL) return;
    no_t *p = lista->ini;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}
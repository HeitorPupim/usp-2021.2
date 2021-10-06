#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node No;
typedef struct Lista;
void insertInicio(Lista *lista, int valor);
void InsertFim(Lista *lista, int valor);
void printLista(Lista *lista);
void removerElemento(Lista *lista, int valor);
No* removerPrimeiroNO(Lista *lista);



#endif //LISTA_ENCADEDADA_H
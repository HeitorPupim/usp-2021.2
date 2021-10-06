#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int num;
typedef struct lista_st lista_t;

lista_t *cria();
void destroi(lista_t *lista);

void popularLista(char *numero);

void insere(lista_t *lista, num x);
void remover(lista_t *lista, num x);

void imprimir(lista_t *lista);
int tamanho(lista_t *lista);

#endif // LISTA_H
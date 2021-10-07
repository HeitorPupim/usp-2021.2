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
void insertInicio(lista_t *lista, int valor);
void remover(lista_t *lista, num x);

void imprimir(lista_t *lista);
int tamanho(lista_t *lista);

int esta_na_lista(lista_t *lista, int x);
int encontrarPosicao(lista_t *lista, int pos);
int igual(lista_t *lista_1,lista_t *lista_2);
int maior(lista_t *lista_1,lista_t *lista_2);
int menor(lista_t *lista_1,lista_t *lista_2);
void soma(lista_t *lista_1,lista_t *lista_2, lista_t *listaSoma);

#endif // LISTA_H
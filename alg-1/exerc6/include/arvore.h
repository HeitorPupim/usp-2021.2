#ifndef ARVORE_H
#define ARVORE_H

#include <util.h>
#include <assert.h>

typedef long int elem;

typedef struct no_st no_t;

struct no_st {
    elem info; //LONG INT
    char *CPF, *Nome, *Idade, *Saldo;
    no_t *esq, *dir;
};

typedef struct arvore_st {
    no_t *raiz;
} arvore_t;

arvore_t *criarArvore();
no_t *criaNo(char* CPF,long int CPFnum, char* Nome, char* Idade, char* Saldo);
int esta_vazia(arvore_t *a);
void destruirArvore(no_t *raiz);
void imprimir(no_t *raiz);
int altura(no_t *raiz);
no_t *busca(no_t *raiz, elem x);
no_t *buscaPai(no_t *raiz, elem x);
int inserirEsq(arvore_t *a, elem x, elem pai);
int inserirDir(arvore_t *a, elem x, elem pai);
int removerABB(no_t **raiz, elem x);
//int remover(arvore_t *a, elem x);
int Insercao(no_t **raiz, char* CPF,long int CPFnum, char* Nome, char* Idade, char* Saldo);
void preOrdem(no_t *raiz);
void emOrdem(no_t *raiz);
void posOrdem(no_t *raiz);

#endif //ARVORE_H
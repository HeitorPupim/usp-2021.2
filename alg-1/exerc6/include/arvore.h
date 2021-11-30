#ifndef ARVORE_H
#define ARVORE_H

#include <util.h>
#include <assert.h>

/*
Elemento que será inserido com formato de long int
*/
typedef long int elem;

/*
Struct do nó da arvore binária
*/
typedef struct no_st no_t;

/*
Nó da arvore.
*/
struct no_st {
    elem info; //LONG INT
    char *CPF, *Nome, *Idade, *Saldo;
    no_t *esq, *dir;
};
/*
Estrutura da árvore, que contém uma raiz.
*/
typedef struct arvore_st {
    no_t *raiz;
} arvore_t;

/*
Cria uma árvore, é necessário criar uma estrutura arvore_t para ser retornada.
*/
arvore_t *criarArvore();

/*
Cria um nó da arvore com os dados contidos no parâmetro da função.
Depois, retorna um nó com formato de no_t
*/
no_t *criaNo(char* CPF,long int CPFnum, char* Nome, char* Idade, char* Saldo);

/*
Verifica se a árvore está vazia, se estiver, retorna 1.
Caso contrário, retorna 0.
*/
int esta_vazia(arvore_t *a);

/*
Percorre os nós percorrendo a sub-árvore esquerda e depois a sub-arvore direita.
*/
void destruirArvore(no_t *raiz);
/*
Imprime a ordem da árvore binária contendo os elementos inseridos como "info" da estrutura no_t
*/
void imprimir(no_t *raiz);

/*
Retorna a altura da árvore.
*/
int altura(no_t *raiz);

/*
Retorna um nó que contém as características filtradas pela key "elem x". Se não for encontrádo, retorna NULL
*/
no_t *busca(no_t *raiz, elem x);
/*
Retorna um nó que é "pai" do nó filtrado pela key "elem x".
*/
no_t *buscaPai(no_t *raiz, elem x);
/*
Remove um elemento da árvore, filtrado pela key "elem x"
*/
int removerABB(no_t **raiz, elem x);

/*
Insere um elemento na árvore binária de busca, nos formatos desejados, conforme a raiz e o nó anterior.
*/
int Insercao(no_t **raiz, char* CPF,long int CPFnum, char* Nome, char* Idade, char* Saldo);
/*
Imprime árvore em Preorder
*/
void preOrdem(no_t *raiz);
/*
Imprime árvore em Inorder
*/
void emOrdem(no_t *raiz);
/*
Imprime árvore em Postorder
*/
void posOrdem(no_t *raiz);

#endif //ARVORE_H
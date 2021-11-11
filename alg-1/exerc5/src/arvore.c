#include <arvore.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct no_st {
    elem info;
    no_t *esq, *dir;
};


arvore_t *criarArvore() {
    arvore_t *a = malloc(sizeof(arvore_t));
    a->raiz = NULL;

    return a;
}

int esta_vazia(arvore_t *a) {
    assert(a != NULL);
    if (a->raiz == NULL) return 1;

    return 0;
}

// Chega até uma folha, remove ela, volta pro nó anterior
void destruirArvore(no_t *raiz) {
    if (raiz != NULL) {
        destruirArvore(raiz->esq);
        destruirArvore(raiz->dir);
        free(raiz);
    }
}

void imprimir(no_t *raiz) {
    if (raiz != NULL) {
        printf("%d(", raiz->info);
        imprimir(raiz->esq);
        printf(", ");
        imprimir(raiz->dir);
        printf(")");
    } else {
        printf("null");
    }
}

int altura(no_t *raiz) {
    if (raiz == NULL) return 0;

    int alt_esq = 1 + altura(raiz->esq);
    int alt_dir = 1 + altura(raiz->dir);

    if (alt_esq > alt_dir)
        return alt_esq;
    else
        return alt_dir;
}

no_t *busca(no_t *raiz, elem x) {
    if (raiz == NULL) return NULL;

    if (raiz->info == x) return raiz;

    no_t *p = busca(raiz->esq, x);
    // Se n está do lado esquerdo
    if (p == NULL) p = busca(raiz->dir, x);

    return p;
}

no_t *buscaPai(no_t *raiz, elem x) {
    if (raiz == NULL) return NULL;

    if (raiz->esq != NULL && raiz->esq->info == x)
        return raiz;
    
    if (raiz->dir != NULL && raiz->dir->info == x)
        return raiz;

    no_t *p = buscaPai(raiz->esq, x);
    if (p == NULL) p = buscaPai(raiz->dir, x);

    return p;
}

// se pai == -1 -> inserir na raiz
// caso contrario, insere no esquerdo de pai
int inserirEsq(arvore_t *a, elem x, elem pai) {
    no_t *p = malloc(sizeof(no_t));

    p->esq = NULL;
    p->dir = NULL;
    p->info = x;

    if (pai == -1) { // inserir na raiz
        if (a->raiz == NULL) {
            a->raiz = p;
        } else {
            free(p);
            return 0;
        }
    } else {
        no_t *aux = busca(a->raiz, pai);
        if (aux != NULL && aux->esq == NULL) {
            aux->esq = p;
        } else {
            free(p);
            return 0;
        }
    }

    return 1;
}

int inserirDir(arvore_t *a, elem x, elem pai) {
    no_t *p = malloc(sizeof(no_t));

    p->esq = NULL;
    p->dir = NULL;
    p->info = x;

    if (pai == -1) { // inserir na raiz
        if (a->raiz == NULL) {
            a->raiz = p;
        } else {
            free(p);
            return 0;
        }
    } else {
        no_t *aux = busca(a->raiz, pai);
        if (aux != NULL && aux->dir == NULL) {
            aux->dir = p;
        } else {
            free(p);
            return 0;
        }
    }

    return 1;
}

int remover(arvore_t *a, elem x) {
    no_t *p, *pai;
    int eh_esq;

    // 1a etapa: setar p e pai
    if (a->raiz != NULL && a->raiz->info == x) { // x é a raiz
        p = a->raiz;
        pai = NULL;
    } else {
        pai = buscaPai(a->raiz, x);
        if (pai != NULL) {
            if (pai->esq != NULL && pai->esq->info == x) {
                p = pai->esq;
                eh_esq = 1;
            } else {
                eh_esq = 0;
                p = pai->dir;
            }
        } else { // pai é null (elemento nao existe)
            p = NULL;
        }
    }

    // 2a etapa: remover p
    if (p == NULL) {
        return 0;
    } else {
        if (p->esq == NULL && p->dir == NULL) { // remove p como folha
            if (pai == NULL) {
                a->raiz = NULL;
            } else {
                if (eh_esq)
                    pai->esq = NULL;
                else
                    pai->dir = NULL;
            }
            free(p);
            return 1; // removeu com sucesso
        } else { // esquerdo existe e/ou direito existe
            if (p->esq != NULL) {
                p->info = p->esq->info;
                p->esq->info = x;
            } else {
                p->info = p->dir->info;
                p->dir->info = x;
            }
            return remover(a, x);
        }
    }

    return 0;
}

void preOrdem(no_t *raiz){
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(no_t *raiz){
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->info);
        emOrdem(raiz->dir);
    }
}

void posOrdem(no_t *raiz){
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->info);
    }
}
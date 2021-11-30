#include <arvore.h>

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

void destruirArvore(no_t *raiz) {
    if (raiz != NULL) {
        destruirArvore(raiz->esq);
        destruirArvore(raiz->dir);
        free(raiz->Nome);
        free(raiz->Idade);
        free(raiz->CPF);
        free(raiz->Saldo);
        free(raiz);
    }
}

void imprimir(no_t *raiz) {
    if (raiz != NULL) {
        printf("%ld(", raiz->info);
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

no_t *busca(no_t *raiz, elem x){
    if (raiz == NULL) return NULL;

    if (raiz->info == x) return raiz;

    else if (x < raiz->info)
        return busca(raiz->esq, x);

    else   //(x > raiz->info)
        return busca(raiz->dir, x);

}

no_t *buscaPai(no_t *raiz, elem x) {
    if (raiz == NULL) return NULL;

    if (raiz->esq != NULL && raiz->esq->info == x)
        return raiz;
    
    if (raiz->dir != NULL && raiz->dir->info == x)
        return raiz;

    no_t *p;
    
    if (x < raiz->info)
        p = buscaPai(raiz->esq, x);

    else if (x > raiz->info) 
    p = buscaPai(raiz->dir, x);

    return p;
}

int removerABB(no_t **raiz, elem x) {
    if (*raiz == NULL)
        return 0;
    else if (x > (*raiz)->info)
        return removerABB(&(*raiz)->dir, x);
    else if (x < (*raiz)->info)
        return removerABB(&(*raiz)->esq, x);
    else {
        // Se for folha
        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
            free((*raiz)->CPF);
            free((*raiz)->Nome);
            free((*raiz)->Idade);
            free((*raiz)->Saldo);
            free(*raiz);
            *raiz = NULL;
        }
        // Se esq for null, então dir != null
        else if ((*raiz)->esq == NULL) {
            no_t *aux = *raiz;
            *raiz = (*raiz)->dir;
            free(aux->CPF);
            free(aux->Nome);
            free(aux->Idade);
            free(aux->Saldo);
            free(aux);
        }
        // Se dir for null, então esq != null
        else if ((*raiz)->dir == NULL) {
            no_t *aux = *raiz;
            *raiz = (*raiz)->esq;
            free(aux->CPF);
            free(aux->Nome);
            free(aux->Idade);
            free(aux->Saldo);
            free(aux);
        }
        // esq e dir != null
        else {
            no_t *aux = (*raiz)->dir;
            while (aux->esq != NULL) { // Busca pelo maior elem da esq
                aux = aux->esq;
            }
            // aux aponta para o maior elem

            (*raiz)->info = aux->info; // Swapa com a raiz

            // remove o aux
            return removerABB(&(*raiz)->dir, aux->info);
        }
        return 1;
    }
}
void preOrdem(no_t *raiz){
    if (raiz != NULL) {
        printf("%ld\n", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(no_t *raiz){
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%ld\n", raiz->info);
        emOrdem(raiz->dir);
    }
}

void posOrdem(no_t *raiz){
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%ld\n", raiz->info);
    }
}

int Insercao(no_t **raiz, char* CPF,long int CPFnum, char* Nome, char* Idade, char* Saldo) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(no_t));
        (*raiz)->CPF = CPF;
        (*raiz)->info = CPFnum;
        (*raiz)->Nome = Nome;
        (*raiz)->Idade = Idade;
        (*raiz)->Saldo = Saldo;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else if(CPFnum == (*raiz)->info){
        return 0;
    } else if(CPFnum > (*raiz)->info){
        return Insercao(&(*raiz)->dir, CPF, CPFnum, Nome, Idade, Saldo);
    } else{
        return Insercao(&(*raiz)->esq, CPF, CPFnum, Nome, Idade, Saldo);
    }
    return 1;
}
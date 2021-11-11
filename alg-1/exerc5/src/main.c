/*
 * Nome: João Pedro Rodrigues Freitas
 * N USP: 11316552
 * Exercício 2
 * Algoritmos e estrutura de dados I
 */
#include <stdio.h>
#include <stdlib.h>
#include <arvore.h>

int main() {
    arvore_t *a = criarArvore();

    inserirEsq(a, 1, -1);
    inserirEsq(a, 2, 1);
    inserirDir(a, 3, 1);
    inserirEsq(a, 4, 3);
    inserirDir(a, 5, 3);
    inserirEsq(a, 6, 4);

    imprimir(a->raiz);
    printf("\n");

    //remover(a, 1);
    
    //imprimir(a->raiz);
    //printf("\n");

    preOrdem(a->raiz);
    printf("\n");
    emOrdem(a->raiz);
    printf("\n");
    posOrdem(a->raiz);
    printf("\n");

    destruirArvore(a->raiz);
    free(a);


    return EXIT_SUCCESS;
}
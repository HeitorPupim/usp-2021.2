#include <util.h>
#include <stdio.h>
#include <stdlib.h>
#include <arvore.h>
#include <cliente.h>


int main() {
    arvore_t *a = criarArvore();

    int numOp;

    scanf("%d\n", &numOp);

    char *CPF, *Nome, *Idade, *Saldo;

    long int CPFnum;


    for (int i = 0; i < numOp; i++)
    {
        CPF = readCPF(';');
        CPFnum = atol(CPF);
        Nome = readline(';');
        Idade = readline(';');
        Saldo = readline('\n');
        
        Insercao(a, a->raiz, CPFnum);
        
        free(CPF);
        free(Nome);
        free(Idade);
        free(Saldo);
    }
        
    printf("Inorder\n");
    emOrdem(a->raiz);
    printf("\n");
    printf("Preorder\n");
    preOrdem(a->raiz);
    printf("\n");
    printf("Postorder\n");
    posOrdem(a->raiz);
    printf("\n");

    destruirArvore(a->raiz);
    free(a);

    return EXIT_SUCCESS;
}
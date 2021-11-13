#include <util.h>
#include <stdio.h>
#include <stdlib.h>
#include <arvore.h>

int main() {

    //arvore_t *a = criarArvore();

    int numOp;

    scanf("%d\n", &numOp);

    printf("numero de operacoes = %d\n", numOp);
    char *CPF, *Nome, *Idade, *Saldo;

    long int CPFnum, CPFaux;

    for (int i = 0; i < numOp; i++)
    {
        CPF = readCPF(';');
        CPFnum = atol(CPF);
        Nome = readline(';');
        Idade = readline(';');
        Saldo = readline('\n');

        if (i == 0)
        {
            CPFaux = CPFnum;
        }
        
        printf("CPF LIDO: %s, CPFconv; %ld NOME: %s, Idade: %s, Saldo: %s\n", CPF, CPFnum, Nome, Idade, Saldo);
        if (CPFnum > CPFaux)
        {
            printf("é maior\n");
        }
        else 
        {
            printf("é menor\n");
        } 
                

    }
    
    

    


    


    /* 
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

    */
    return EXIT_SUCCESS;
}
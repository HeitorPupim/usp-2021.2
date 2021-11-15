#include <util.h>
#include <stdio.h>
#include <stdlib.h>
#include <arvore.h>
#include <cliente.h>


int main() {

    cadastro_t *cadastro = criarCadastro();

    int numOp;

    scanf("%d\n", &numOp);

    char *CPF, *Nome, *Idade, *Saldo;

    IDCliente CPFnum;


    for (int i = 0; i < numOp; i++)
    {
        CPF = readCPF(';');
        CPFnum = atol(CPF);
        Nome = readline(';');
        Idade = readline(';');
        Saldo = readline('\n');
        
        cadastrarCliente(cadastro, cadastro->raiz, CPFnum);
        //Insercao(a, a->raiz, CPFnum);
        
        free(CPF);
        free(Nome);
        free(Idade);
        free(Saldo);
    }
        
    printf("Inorder\n");
    emOrdem(cadastro->raiz);
    printf("\n");
    printf("Preorder\n");
    preOrdem(cadastro->raiz);
    printf("\n");
    printf("Postorder\n");
    posOrdem(cadastro->raiz);
    printf("\n");

    destruirCadastros(cadastro->raiz);
    //destruirArvore(a->raiz);
    free(cadastro);

    return EXIT_SUCCESS;
}
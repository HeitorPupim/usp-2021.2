#include <util.h>
#include <arvore.h>
#include <cliente.h>

int main() {

    cadastro_t *cadastro = criarCadastro();

    int numOperacoes;
    scanf("%d\n", &numOperacoes);

    char *CPF, *Nome, *Idade, *Saldo;//leitura
    IDCliente CPFnum; //conversão

    for (int i = 0; i < numOperacoes; i++){
        CPF = readCPF(';');
        CPFnum = atol(CPF);
        Nome = readline(';');
        Idade = readline(';');
        Saldo = readline('\n');
        
        cadastrarCliente(cadastro, cadastro->raiz, CPFnum);
        
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
    free(cadastro);
    return EXIT_SUCCESS;
}
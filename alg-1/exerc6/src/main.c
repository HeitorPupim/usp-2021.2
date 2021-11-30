#include <util.h>
#include <arvore.h>
#include <cliente.h>

int main(){
    cadastro_t *cadastro= criarCadastro();

    int numOperacoes;
    scanf("%d\n", &numOperacoes);
    char *CPF, *Nome, *Idade, *Saldo;   
    long int CPFnum;                   

    //Cadastros iniciais:
    for (int i = 0; i < numOperacoes; i++){
        CPF = readCPF(';');
        CPFnum = atol(CPF); 
        Nome = readline(';');
        Idade = readline(';');
        Saldo = readline('\n');
            
        cadastrarCliente(&cadastro->raiz,CPF,CPFnum, Nome, Idade, Saldo);
    }

    //Operações:
    char operacao;
    scanf("%c\r\n", &operacao);
    switch (operacao){
    case 'B':
        OPBuscarCliente(cadastro);
        break;
    case 'I':
        OPInserirNovoCliente(cadastro);
        break;
    case 'R':
        OPRemoverCliente(cadastro);
        break;
    default:
        break;
    }
    printf("\n");
    destruirCadastros(cadastro->raiz);
    free(cadastro);
    return EXIT_SUCCESS;
}
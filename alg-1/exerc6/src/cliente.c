#include <cliente.h>


struct cliente_st {
    IDCliente CPFnum;
    char *CPF, *Nome, *Idade, *Saldo;
    cliente_t *esquerdo, *direito;
};

cadastro_t *criarCadastro(){
    cadastro_t *cadastro = criarArvore();
    return cadastro;
}

int cadastroVazio(cadastro_t *cadastro){
    int listaCadastroVazio = esta_vazia(cadastro);
    return listaCadastroVazio;
}

void destruirCadastros(cliente_t *cliente){
    destruirArvore(cliente);
}

void imprimirCadastros(cliente_t *cliente){
    imprimir(cliente);
}

cliente_t *buscaCliente(cliente_t *cliente, IDCliente CPFnum){
    cliente_t *c = busca(cliente, CPFnum);
    return c;
}

void cadastrarCliente(cliente_t** cliente, char *CPF, IDCliente CPFnum, char* Nome,char* Idade, char* Saldo){
    Insercao(cliente, CPF, CPFnum, Nome, Idade, Saldo);
}

void OPInserirNovoCliente(cadastro_t *cadastro)
{
    char *CPF, *Nome, *Idade, *Saldo;   
    long int CPFnum;     
    
    CPF = readCPF(';');
    CPFnum = atol(CPF); 
    Nome = readline(';');
    Idade = readline(';');
    Saldo = readline('\n');

    Insercao(&cadastro->raiz,CPF,CPFnum, Nome, Idade, Saldo);

    printf("Preorder\n");
    preOrdem(cadastro->raiz);
}

void OPBuscarCliente(cadastro_t *cadastro){
     char* aux = readCPF('\n');
        
        long int x = atol(aux);

        cliente_t *cliente = busca(cadastro->raiz, x);
        printf("Conta :: %s\nCPF :: ",cliente->Nome);
        for(int i = 0; i < 11; i++){
            printf("%c", aux[i]);
            if (i == 2 || i == 5) printf(".");
            if(i == 8) printf("-");
        }
        
        printf("\nIdade :: %s\nSaldo atual :: R$ %s\n",  cliente->Idade, cliente->Saldo);
        free(aux);
}

void OPRemoverCliente(cadastro_t *cadastro){
    char* aux = readCPF('\n');
    long int x = atol(aux);

    cliente_t *cliente = buscaCliente(cadastro->raiz, x);
    printf("Conta :: %s\nCPF :: ",cliente->Nome);

    for(int i = 0; i < 11; i++)
    {
        printf("%c", aux[i]);
        if (i == 2 || i == 5) printf(".");
        if(i == 8) printf("-");
    }
    
    printf("\nIdade :: %s\nSaldo atual :: R$ %s\n",  cliente->Idade, cliente->Saldo);
    removerABB(&cadastro->raiz, x);

    printf("Preorder\n");
    preOrdem(cadastro->raiz);
    free(aux);
}
#include <cliente.h>

struct cliente_st {
    IDCliente CPF;
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

cliente_t *buscaCliente(cliente_t *cliente, IDCliente CPF){
    cliente_t *c = busca(cliente, CPF);
    return c;
}

void cadastrarCliente(cadastro_t *cadastro, cliente_t *cliente, IDCliente CPF){
    Insercao(cadastro,cliente,CPF);
}
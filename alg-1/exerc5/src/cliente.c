#include <cliente.h>

struct cliente_st {
    IDCliente CPF;
    cliente_t *esquerdo, *direito;
};

//criar arvore
cadastro_t *criarCadastro(){
    cadastro_t *cadastro = criarArvore();
    return cadastro;
}

//se estiver vazio..
int cadastroVazio(cadastro_t *cadastro){
    int listaCadastroVazio = esta_vazia(cadastro);
    return listaCadastroVazio;
}

//free nos cadastros..
void destruirCadastros(cliente_t *cliente)
{
    destruirArvore(cliente);
}

//imprime os cadastros na ordem de arvore
void imprimirCadastros(cliente_t *cliente)
{
    imprimir(cliente);
}

//buscar
cliente_t *buscaCliente(cliente_t *cliente, IDCliente CPF)
{
    cliente_t *c = busca(cliente, CPF);
    return c;
}

//inserir
void cadastrarCliente(cadastro_t *cadastro, cliente_t *cliente, IDCliente CPF)
{
    Insercao(cadastro,cliente,CPF);
}
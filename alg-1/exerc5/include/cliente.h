#ifndef CLIENTE_H
#define CLIENTE_H

#include <arvore.h>

typedef struct no_st cliente_t;
typedef long int IDCliente;
typedef struct arvore_st
{
    cliente_t *raiz;
}cadastro_t;

//criar arvore
cadastro_t *criarCadastro();

//se estiver vazio..
int cadastroVazio(cadastro_t *cadastro);

//free nos cadastros..
void destuirCadastros(cliente_t *cliente);
//imprime os cadastros na ordem de arvore
void imprimirCadastros(cliente_t *cliente);
//buscar
cliente_t *buscaCliente(cliente_t *cliente, IDCliente CPF);

//inserir
void cadastrarCliente(cadastro_t *cadastro, cliente_t *cliente, IDCliente CPF);


#endif
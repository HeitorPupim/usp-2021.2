#ifndef CLIENTE_H
#define CLIENTE_H

#include <arvore.h>

typedef no_t cliente_t; 

typedef long int IDCliente;

typedef arvore_t cadastro_t;

//criar cadastro
cadastro_t *criarCadastro();
//se estiver vazio..
int cadastroVazio(cadastro_t *cadastro);
//free nos cadastros..
void destruirCadastros(cliente_t *cliente);
//imprime os cadastros na ordem de arvore
void imprimirCadastros(cliente_t *cliente);
//buscar
cliente_t *buscaCliente(cliente_t *cliente, IDCliente CPFnum);
//inserir
void cadastrarCliente(cliente_t** cliente, char *CPF, IDCliente CPFnum, char* Nome,char* Idade, char* Saldo);

//Operacoes:
void OPInserirNovoCliente(cadastro_t *cadastro);
void OPBuscarCliente(cadastro_t *cadastro);
void OPRemoverCliente(cadastro_t *cadastro);

#endif
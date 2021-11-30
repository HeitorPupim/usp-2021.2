#ifndef CLIENTE_H
#define CLIENTE_H
#include <arvore.h>

//estrutrua de "cliente"
typedef no_t cliente_t; 

//long int utilizado para armazenar o CPF
typedef long int IDCliente;

//cadastro em formato de árvore.
typedef arvore_t cadastro_t;

// Criando estrutura que contém cada cliente.
cadastro_t *criarCadastro();

//inicia o script criando cadastro.
int cadastroVazio(cadastro_t *cadastro);

//termina o script apagando os cadastros e limpando toda a memória alocada.
void destruirCadastros(cliente_t *cliente);
//imprime a lógica da ABB para os clientes com registro dado pelo CPF.
void imprimirCadastros(cliente_t *cliente);
//Buscar cliente, retornando um cliente_c, que poderá ser acessado em outra parte
cliente_t *buscaCliente(cliente_t *cliente, IDCliente CPFnum);
//Insere na Arvore um cliente com CPF em string, CPF em numero formatado, Nome, Idade e Saldo.
void cadastrarCliente(cliente_t** cliente, char *CPF, IDCliente CPFnum, char* Nome,char* Idade, char* Saldo);

/*
Operações da conta bancária:
Inserção: insere um novo cliente depois do término das operações de inserção iniciais.
*/
void OPInserirNovoCliente(cadastro_t *cadastro);
/*
Operação de Busca: busca um cliente, conforme o CPF informado, retornando a formatação desejada.
*/
void OPBuscarCliente(cadastro_t *cadastro);
/*
Operação de remoção:
Remove um cliente dos cadastros, trazendo para o lugar o menor cpf da sub-árvore da direita, que contém CPFs maiores que a raíz.
*/
void OPRemoverCliente(cadastro_t *cadastro);

#endif
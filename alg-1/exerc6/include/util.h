#ifndef UTIL_H
#define UTIL_H

#define BUFFER 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Lê a entrada e devolve uma string conforme é apresentado em cada campo do csv. A parada serve para informar qual caractere do será a condição de parada do CSV, podendo ser ";" ou "\n"
*/
char *readline(char parada);

/*
Lê entrada e retorna o CPF sem pontos ou traços, contendo apenas números - facilita conversão em long int. O char parada tem a mesma lógica do readline.
*/
char *readCPF(char parada);

#endif
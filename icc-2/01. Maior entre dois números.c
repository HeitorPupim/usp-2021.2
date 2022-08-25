// fazer um programa que lê o maior e menor entre 2 inteiros
// e imprima o maior deles..
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b; //inteiros declarados
    //pegando o input de cada valor
    scanf("%d\n", &a);
    scanf("%d", &b);
    // if ternário:
    (a > b) ? printf("%d", a) : printf("%d", b) ;
    
    return 0;
}
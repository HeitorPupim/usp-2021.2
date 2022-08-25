#include <stdio.h>
#include <stdlib.h>
#include "util.h"

// Funçao de alocar tamanho do vetor.
int* alocar_tamanho_vetor(int *vetor, int array_size)
{
    int *array_input;
    array_input = (int*)realloc(vetor,sizeof(int)*array_size);
    return array_input;
} // 3.

void ler_vetor(int array_size, int *vetor)
{
    for(int i=0; i<array_size; i++){
        //printf("digite o %d° valor:\n", i+1);
        scanf("%d", &vetor[i]);
    }
}

void imprimir_vetor(int tamanho, int *vetor){
    for(int i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");   
}    
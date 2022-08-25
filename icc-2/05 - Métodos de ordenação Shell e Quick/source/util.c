#include <util.h>


int tamanhoVetor()
{   
    int num_elem;
    scanf("%d\n", &num_elem);
    return num_elem;
}
int* criarVetor(int num_elem)
{
    int *vetor = (int*)malloc(sizeof(int*)*num_elem);
    for (int i = 0; i < num_elem; i++)
    {
        scanf("%d\n", &vetor[i]);
    }
    return vetor;
}
int *criarSubVetor(int *vetor,int tamSubVetor)
{
    int *SubVetor= (int*)malloc(sizeof(int)*tamSubVetor);
    for (int i = 0; i < tamSubVetor; i++)
    {
        SubVetor[i] = vetor[i];
    }
    return SubVetor;
}
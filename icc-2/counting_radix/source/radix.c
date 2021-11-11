#include <radix.h>

int GetNumAtual(int numAtual, int pos, int base, int numDigitos)
{
    while (numDigitos > pos + 1)
    {
        numAtual = numAtual % (int)pow(base, numDigitos - 1);
        numDigitos--;
    }
    numAtual = numAtual / (int)pow(base, numDigitos - 1);
    return numAtual;
}

int countDigitos(int numAtual, int base)
{
    int i = 0;
    while (pow(base, i) <= numAtual)
        i++;
    return i;
}

void radixSort(int *v, int numElem, int base, int numDigitos)
{   
    int *tmp = (int *)malloc(numElem * sizeof(int));
    int *count = malloc((base + 1) * sizeof(int));

    int posicao, digito;

    for (int k = 0; k < numDigitos; k++)
    {
        for (int j = 0; j < base; j++)
            count[j] = 0;
        for (int i = 0; i < numElem; i++)
        {
            digito = GetNumAtual(v[i], k, base, numDigitos);
            count[digito + 1]++;
        }
        for (int j = 1; j < base; j++)
            count[j] += count[j - 1];
        for (int i = 0; i < numElem; i++)
        {
            digito = GetNumAtual(v[i], k, base, numDigitos);
            posicao = count[digito];
            count[digito] += 1;
            tmp[posicao] = v[i];
        }
        for (int i = 0; i < numElem; i++)
        {
            v[i] = tmp[i];
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    free(tmp);
    free(count);
}
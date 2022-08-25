#include <util.h>
#include <radix.h>
#include <counting.h>

int main()
{
    int kE; //chaves ou expoente
    int numElem; // numero de elementos 

    int numDigitos = 0, numAtual;

    scanf("%d", &kE);
    scanf("%d", &numElem);

    int *v = (int *)malloc(numElem * sizeof(int));
    int base = pow(2,kE);
    
    //Lendo os N elementos de um vetor V..
    for (int i = 0; i < numElem; i++){
        scanf("%d", &v[i]);
        numAtual = countDigitos(v[i], base);
        if (numAtual > numDigitos)
            numDigitos = numAtual;
    }
    //Aplicação do método desejado

    countingSort(v, numElem, kE);
    //radixSort(v, numElem, base, numDigitos);
    
    //limpando memória..
    free(v); 
    return EXIT_SUCCESS;
}

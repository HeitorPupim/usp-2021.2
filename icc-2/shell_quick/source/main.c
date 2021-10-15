#include <util.h>
#include <shell.h>

int main()
{   
    int n, melhor_metodo;

    n = tamanhoVetor();
    int *vetor = criarVetor(n); //crio o vetor inicial.
    
    for (int i = 1; i <= n; i++)
    {   
        //cria um subvetor para cada interaçao
        //printf("subvetor %d\n", i);
        int *SubVetor = criarSubVetor(vetor, i);
 
        melhor_metodo = shellSort(vetor, i);
        
        (melhor_metodo == 0) ? 
            printf("- ") :
            printf("%d ",melhor_metodo);
        
        free(SubVetor); 
    }
    free(vetor);
    return 0;
}

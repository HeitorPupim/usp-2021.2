#include <util.h>
#include <shell.h>
#include <quick.h>

int main()
{   
    int n, metodoQuick = 0, metodoShell = 0;

    n = tamanhoVetor();
    int *vetor = criarVetor(n); //crio o vetor inicial.
    int *VetorSomaQuick = malloc(sizeof(int)*n);

    for (int i = 1; i <= n; i++)
    {   
        //int troca = 0, comparacoes = 0;

        int *SubVetor1 = criarSubVetor(vetor, i);
        int *SubVetor2 = criarSubVetor(vetor, i);
        

        
        metodoShell = shellSort(SubVetor1, i);

        

        QuickSort(SubVetor2, 0, i-1, VetorSomaQuick, i);

        metodoQuick = RetornaValorSoma(VetorSomaQuick, i);

        //printf("shell = %d\n", metodoShell);
        //printf("quick = %d\n", metodoQuick);

        
        
        if (i == n)
        {
            if (metodoShell == metodoQuick) printf("-");
            else if (metodoQuick > metodoShell) printf("S");
            else if (metodoQuick < metodoShell) printf("Q");
        }else{
            if (metodoQuick > metodoShell) printf("S ");
            else if (metodoQuick < metodoShell) printf("Q ");
            else if(metodoShell == metodoQuick) printf("- ");
        }
    
        
        free(SubVetor1);
        free(SubVetor2);
    }
    free(vetor);
    free(VetorSomaQuick);
    return 0;
}

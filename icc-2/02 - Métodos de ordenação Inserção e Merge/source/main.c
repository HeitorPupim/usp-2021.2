#include <stdio.h>
#include <util.h>
#include <insertion.h>
#include <merge.h>

int main()
{
    int qntd_de_vetores;
    int *vetor=NULL;
    
    scanf("%d", &qntd_de_vetores);
    int vetor_tamanhos[qntd_de_vetores];
    
    for(int i = 0; i < qntd_de_vetores; i++){
        scanf("%d", &vetor_tamanhos[i]);
    }

    for (int i = 0; i < qntd_de_vetores; i++){
        vetor = alocar_tamanho_vetor(vetor, vetor_tamanhos[i]); // pegando o tamanho do vetor.
        ler_vetor(vetor_tamanhos[i], vetor);

        //imprimir_vetor(vetor_tamanhos[i], vetor);
        insertion_sort(vetor,vetor_tamanhos[i]);
        merge_sort(vetor, vetor_tamanhos[i]);
    }
    free(vetor);
	return 0;
}
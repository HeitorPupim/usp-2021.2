
#include <stdio.h>

// int *vetor;
// vetor = (int*)malloc(sizeof(int)*n); -> aloquei o tamanho para n 


void insertion_sort(int *vetor, int tamanho){
    int count_troca = 0;
	int count_comparacoes = 0;
	int aux_comparacoes = 0;
	int vetor_copia[tamanho];


	for(int i=0; i<tamanho; i++){
		vetor_copia[i] = vetor[i];
	}

	for(int i = 1; i < tamanho; i++){
		int aux = vetor_copia[i]; 
		int j = i - 1;
		count_troca++;

		while(j >= 0 && vetor_copia[j] > aux){ // se for maior que o anterior, troca.
			vetor_copia[j + 1] = vetor_copia[j];
			j--;
			aux_comparacoes++;
			count_troca++;
		}
		if (j >= 0){
			count_comparacoes++;
		}
		vetor_copia[j + 1] = aux; //fim da posiçao.
		count_troca++; 
	}
	count_comparacoes = aux_comparacoes + count_comparacoes;
    printf("I %d %d %d\n", tamanho, count_troca, count_comparacoes);
}
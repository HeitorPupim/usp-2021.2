#include <stdlib.h>
#include <stdio.h>
#include <merge.h>

void merge_sort(int vetor[], int tamanho){
	int *vetor_temp = malloc(sizeof(int) * tamanho);
	if(vetor_temp == NULL){
		printf("erro ao alocar vetor\n");
		exit(-1);
	}
	int comparacao=0;
	int troca=0;

	merge(vetor, 0, tamanho - 1, vetor_temp, &comparacao, &troca);

	free(vetor_temp);
	printf("M %d %d %d\n", tamanho, troca, comparacao);
}

void merge(int vetor[], int comeco, int fim, int vetor_temp[], int *comparacao, int *troca){
	// caso base
	if(comeco >= fim){
		return;
	}
	
	int meio = (comeco + fim)/2;

	merge(vetor, comeco, meio, vetor_temp, comparacao, troca);
	merge(vetor, meio+1, fim, vetor_temp, comparacao, troca);
	merge2vetores(vetor, comeco, meio, meio+1, fim, vetor_temp, comparacao, troca);
}

void merge2vetores(int vetor[], int comeco1, int fim1, int comeco2, int fim2, int vetor_temp[], int* comparacao, int *troca){
	int i1 = comeco1;
	int i2 = comeco2;
	int j = 0;

	while(i1 <= fim1 && i2 <= fim2){
		*comparacao+=1;
		//printf("C %d %d\n", i1, i2);
		//printf("valores: %d %d\n", vetor[i1], vetor[i2]);
		if(vetor[i1] <= vetor[i2]){
			vetor_temp[j] = vetor[i1];
			*troca+=1;
			j++;
			i1++;
		}
		else{
			vetor_temp[j] = vetor[i2];
			*troca+=1;
			j++;
			i2++;
		}
	}
	while(i1 <= fim1){
		vetor_temp[j] = vetor[i1];
		*troca+=1;
		j++;
		i1++;
	}
	while(i2 <= fim2){
		vetor_temp[j] = vetor[i2];
		*troca+=1;
		j++;
		i2++;        
	}
	j = 0;

	for(int i = comeco1; i <= fim2; i++){
		vetor[i] = vetor_temp[j];
		*troca+=1;
		j++;
	}
}

#include <stdio.h>

// int *vetor;
// vetor = (int*)malloc(sizeof(int)*n); -> aloquei o tamanho para n 


void insertionSort(int a[], int n) //parametro eh um vetor e o numero de elementos do vetor
{
	int troca = 0, comparacoes = 0;

	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		int j = i - 1;
		troca ++;
		while (j >= 0 && a [j] > x)
		{
			a[j+1] = a[j];
			j--;
			troca++;
			comparacoes++;
		}
		a[j + 1] = x;
		troca++;
	}
	
}

void shellSort(int a[], int n) //parametro eh um vetor e o numero de elementos do vetor
{
	int troca = 0, comparacoes = 0;

	int gap = 1;
	while (gap < n)
	{
		gap *= 2;
	}
	gap = (gap/2) - 1;
	for (int i = gap; i < n; i++)
	{
		int x = a[i];
		int j = i - gap;
		troca ++;
		while (j >= 0 && a [j] > x)
		{
			a[j+gap] = a[j];
			j -= gap;
			troca++;
			comparacoes++;
		}
		a[j + gap] = x;
		troca++;
	}
	printf("numero de trocas = %d", troca+comparacoes);	
}
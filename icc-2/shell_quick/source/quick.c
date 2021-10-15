//QUICK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *LerVetor(int n){
	int *a = (int *)malloc(n * sizeof(int));

	if (a == NULL) {
		printf("ERRO\n");
		exit(-1);
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	return a;
}

void _quick(int a[], int c, int f){
  if(c >= f){
    return;
  }
  int m = (c+f)/2;
  int pivot = a[m];
  int i = c;
  int j = f;
  while (1){
    while(a[i] < pivot){
      i++;
    }
    while(a[j] > pivot){
      j--;
    }
    if(j <= i){
      break;
    }
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    j++;
    j--;
  }
  _quick(a, c, j);
  _quick(a, j+1, f);
}

void quick(int a[], int n){
  _quick(a, 0, n-1);
}

int imprimeVetor(int n, int *a) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void destruirVetor(int*a){
  free(a);
}

int main(void) {
  //Numero de elementos do vetor
	int n;
	scanf("%d", &n);
  //Armazena os elementos do vetor
	int *a = LerVetor(n);
  quick(a, n);
	imprimeVetor(n, a);
  destruirVetor(a);
	return 0;
}
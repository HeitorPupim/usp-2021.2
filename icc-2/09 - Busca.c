//Atividade 9-ICC2
#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int a[], int n, int x){
  int c = 0;
  int f = n-1;
  while (c <= f){
    int m = (c+f)/2;
    if(a[m] == x){
      return 1;
    }else if(a[m] < x){
      c = m + 1;
    }else{
      f = m - 1;
    }
  }
  return 0;
}

int imprimeVetor(int n, int *a) {
  for (int i = 0; i < n; i++) {
  printf("%d\n", a[i]);
  }
  return 0;
}

void heapficador (int a[], int p, int u){
  while (p <= u){
    int f = 2*p+1;
    if(f <= u){
      if(f+1 <= u && a[f+1] > a[f]){
        f++;
      }
      if(a[p] < a[f]){
        int tmp = a[p];
        a[p] = a[f];
        a[f] = tmp;
        p=f;
      }else{
        return;
      }
    }else{
      return;
    }
  }
}
void heap (int a[], int n){
  for(int i = n/2; i >= 0; i--){
    heapficador (a, i, n-1);
  }
  for (int i = n-1; i > 0; i--){
    int tmp = a[0];
    a[0] = a[i];
    a[i] = tmp;
    heapficador(a, 0, i-1);
  }
}

int main(void) {
  int N, K;
  scanf ("%d", &N);
  //Vetor principal
  int *vetor = (int*)malloc(sizeof(int*)*N);
  for (int i = 0; i < N; i++){
    scanf("%d", &vetor[i]);
  }
  scanf ("%d", &K);
  //Vetor que armazena os valores K
  int *vetor2 = (int*)malloc(sizeof(int*)*K);
  for (int i = 0; i < K; i++){
    scanf("%d", &vetor2[i]);
  }
  //Vetor que armazena a resposta:
  int *vetor3 = (int*)malloc(sizeof(int*)*K);

  //Ordena o vetor
  heap(vetor, N);

  //Busca os valores
  int x;
  for (int i = 0; i < K; i++){
    x = vetor2[i];
    vetor3[i] = buscaBinaria(vetor, N, x);
  }

  //Resultado
  imprimeVetor(K, vetor3);
  free(vetor);
  return 0;
}
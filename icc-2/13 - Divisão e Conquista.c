#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto_st{
  float x;
  float y;
};

typedef struct ponto_st PONTO;

float min(float a, float b){
  if(a < b){
    return a;
  }else{
    return b;
  }
}

float distancia(PONTO a, PONTO b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void quicksort_(PONTO *v, int inicio, int fim) {
  if (inicio>=fim) {
    return;
  }
  int m= (inicio+fim)/2;
  float pivot=v[m].x;
  int i=inicio;
  int j=fim;
  PONTO temp;
  while (1) {
    while (v[i].x < pivot){
      i++;
    }
    while (v[j].x > pivot) {
      j--;
    }
    if (j<=i) {
      break;
    }
    temp.x = v[i].x;
    temp.y = v[i].y;
    v[i].x = v[j].x;
    v[i].y = v[j].y;
    v[j].x = temp.x;
    v[j].y = temp.y;

    i++;
    j--;
  }
  quicksort_(v, inicio, j);
  quicksort_(v, j+1, fim);
}

void quicksort(PONTO *v, int n) {
  quicksort_(v, 0, n-1);
}

float menorDist_(PONTO *pontos, int i, int f){
  if((f - i) <= 2){
    if((f - i) == 2){
      float d1 = distancia(pontos[i], pontos[i+1]);
      float d2 = distancia(pontos[i+1], pontos[f]);
      float d3 = distancia(pontos[i], pontos[f]);
      return min(d1, min(d2, d3));
    }
    else if((f - i) == 1){
      return distancia(pontos[i], pontos[f]);
    }
    else{
      return 99999;
    }
  }

  int d = (i + f)/2;
  float divisao = pontos[d].x;

  float de = menorDist_(pontos, i, d);
  float dd = menorDist_(pontos, d+1, f);

  float dist_a = min(de, dd);

  float left = divisao - dist_a;
  float right = divisao + dist_a;

  int r;
  for(r = f; r >= d; r--){
    if(pontos[r].x <= right){
      break;
    }
  }

  int l;
  for(l = i; l <= d; l++){
    if(pontos[l].x >= left){
      break;
    }
  }

  for(int a = l; a <= r; a++){
    for(int b = a+1; b <= r; b++){
      dist_a = min(distancia(pontos[a], pontos[b]), dist_a);
    }
  }

  return dist_a;
}

float menorDist(PONTO *pontos, int n){
  quicksort(pontos, n);
  return menorDist_(pontos, 0, n-1);
}

int main() {
  int n;
  scanf("%d", &n);

  PONTO *pontos = (PONTO*) malloc(sizeof(PONTO)*n);
  for(int i = 0; i < n; i++){
    scanf("%f", &pontos[i].x);
    scanf("%f", &pontos[i].y);
  }

  float d = menorDist(pontos, n);

  printf("%.6f", d);

  free(pontos);

  return 0;
}

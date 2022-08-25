#include <stdio.h>
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st{
  int dist_dir;
  int dist_baixo;
};

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

int melhor_caminho_(NODE *v, int index, int n, int m, int *cache){
  if(cache[index] == -1){
    int dir = 0, baixo = 0;
    if(v[index].dist_dir != -1){
      dir = v[index].dist_dir + melhor_caminho_(v, index+1, n, m, cache);
    }
    if(v[index].dist_baixo != -1){
      baixo = v[index].dist_baixo + melhor_caminho_(v, index+m, n, m, cache);
    }

    cache[index] = max(dir, baixo);
  }

  return cache[index];
}

int melhor_caminho(NODE *v, int n, int m){
  int* cache = (int*) malloc(sizeof(int)*n*m);
  for(int i = 0; i < n*m; i++){
    cache[i] = -1;
  }

  int dist = melhor_caminho_(v, 0, n, m, cache);
  free(cache);

  return dist;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  NODE* v = (NODE*) malloc(sizeof(NODE)*n*m);
  for(int i = 0; i < n*m; i++){
    v[i].dist_baixo = -1;
    v[i].dist_dir = -1;
  }

  int edges = (n-1)*m + (m-1)*n;
  int a, b, val;
  for(int i = 0; i < edges; i++){
    scanf("%d %d %d", &a, &b, &val);
    if(b-a == m){
      v[a].dist_baixo = val;
    }else{
      v[a].dist_dir = val;
    }
  }

  int c = melhor_caminho(v, n, m);

  printf("%d", c);

  free(v);

  return 0;
}

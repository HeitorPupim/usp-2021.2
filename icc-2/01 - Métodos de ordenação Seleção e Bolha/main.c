#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char metodo[10];
  int n;
  int *vet;
  scanf("%s",metodo);

  scanf("%d",&n);
  vet = (int*) malloc(sizeof(int)*n);
  for(int i = 0; i < n; i++){
    scanf("%d", &vet[i]);
  }
  
  if(! strcmp(metodo, "selecao")){
    //Selection
    for(int j = 0; j < n; j++){
      
    // posic inicial  

      int menor = j;
      for(int i = j+1; i < n; i++){
        printf("C %d %d\n", menor, i);
        if(vet[menor] > vet[i]){
          menor = i;
        }
       // vet[j] compara com vet[i]
      }
      if(menor != j){
        int aux = vet[menor];
        vet[menor] = vet[j];
        vet[j] = aux;
        printf("T %d %d\n", j, menor);
      }
      // Troca
      
    }
    

  }
  else {
    // Bolha
    
    int sentinela = n-1;
    int ultima_troca;

    while(sentinela != 0) {
      ultima_troca = 0;

      for (int i = 0; i < sentinela; i++){
        
        printf("C %d %d\n", i, i+1);
        
        if (vet[i] > vet[i+1]) {
          // Troca de valores
          int aux = vet[i];
          vet[i] = vet[i+1];
          vet[i+1] = aux;
          printf("T %d %d\n", i, i+1);

          ultima_troca = i;
        }
      }

      sentinela = ultima_troca;
    }
  }

  for(int i = 0; i < n; i++){
    printf("%d ",vet[i]);
  }

  free(vet);
  return 0;
} 

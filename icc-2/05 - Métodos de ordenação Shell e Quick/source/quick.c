#include <util.h>

void QuickSort(int *SubVetor, int c, int f, int *VetorSomaQuick, int fim){
 
  int aux = fim;

  if(c >= f){ //condiç de parada.
    return;
  }
  
  int m = (c+f)/2;
  int pivot = SubVetor[m];
  VetorSomaQuick[aux] += 1;
  int i = c;
  int j = f;
  
  //talvez add uma comp aqui VetorSomaQuick[aux] += 1 ;
  while (1){
    while(SubVetor[i] < pivot){
      i++;
      VetorSomaQuick[aux] += 1; //comparacoes;
    }VetorSomaQuick[aux] += 1; //comparacoes;
    while(SubVetor[j] > pivot){
      j--;
      VetorSomaQuick[aux] += 1 ; //comparacoes++;
    }VetorSomaQuick[aux] += 1; //comparacoes;
    if(j <= i){
      break;
    }
    int tmp = SubVetor[i];
    SubVetor[i] = SubVetor[j];
    SubVetor[j] = tmp;
    i++;
    j--;
    VetorSomaQuick[aux] += 3 ; //troca++;
    //printf("VetorSomaQuick[%d]3 = %d\n", aux, VetorSomaQuick[aux]);
  }
  QuickSort(SubVetor, c, j, VetorSomaQuick, fim);
  QuickSort(SubVetor, j+1, f, VetorSomaQuick, fim);
}

int RetornaValorSoma(int *VetorSomaQuick, int n)
{
  //printf("VetorSomaQuick1[%d] = %d", n, VetorSomaQuick[n]);
  return VetorSomaQuick[n];
}



// int imprimeVetor(int n, int *a) {
// 	for (int i = 0; i < n; i++) {
// 		printf("%d ", a[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }


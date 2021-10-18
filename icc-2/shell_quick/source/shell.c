#include <util.h>
/*
void shellSort(int *SubVetor, int n) {
    int dist = n / 2 - 1;
    int aux; 
    while (dist >= 1) {
        for (int i = dist; i < n; i++) {
            aux = SubVetor[i];
            int j = i;
            while (j >= dist && aux <= SubVetor[j - dist]) {
                SubVetor[j] = SubVetor[j - dist];
                j -= dist; 
            }
            SubVetor[j] = aux;
        }
        dist /= 2;
    }
}

*/

int shellSort(int *SubVetor, int n){
    int copias = 0, comparacoes = 0;

    int gap = 1;
    while(gap < n){
        gap *= 2;
    }
    gap = gap/2 -1;
    //printf("tam. vetor %d, gap  = %d\n", n, gap);
    while (gap > 0){
        for (int i = gap; i < n; i++) {
        int aux = SubVetor[i]; 
        int j = i - gap;

        copias ++;
        while (j >= 0 && SubVetor[j] > aux) {
            SubVetor[j+gap] = SubVetor[j];
            j -= gap;
            copias++;
            comparacoes++;
        }
        if(j >= 0 ) comparacoes++; 
        SubVetor[j+gap] = aux;
        copias++;
        }

        gap /= 2;
    }
    return copias+comparacoes;
}

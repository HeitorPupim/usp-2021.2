#ifndef MERGE_H
#define MERGE_H

void merge2vetores(int vetor[], int comeco1, int fim1, int comeco2, int fim2, int vetor_temp[], int *comparacao, int *troca);
void merge(int vetor[], int comeco, int fim, int vetor_temp[], int *comparacao, int *troca);
void merge_sort(int vetor[], int tamanho);

#endif //MERGE_H
#include <util.h>
/*
int shellSort(int *SubVetor, int n) //parametro eh um vetor e o numero de elementos do vetor
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
		int x = SubVetor[i];
		int j = i - gap;
		troca ++;
		while (j >= 0 && SubVetor[j] > x)
		{
			SubVetor[j+gap] = SubVetor[j];
			j -= gap;
			troca++;
			comparacoes++;
		}
		SubVetor[j + gap] = x;
		troca++;
	}
    return troca+comparacoes;
}
*/
int shellSort(int *SubVetor, int n) {
    int troca = 0, comparacoes = 0;
    int dist = n / 2;
    int aux; // para verificar o valor e trocar as posições do vetor concha, se necessário
    while (dist >= 1) {
        // Para cada i começando na posição 'dist' até n - 1,
        // realiza um insertion sort nas sub-listas dessa distância
        for (int i = dist; i < n; i++) {
            aux = SubVetor[i]; // salva a posição da struct i do vetor
            int j = i;
            troca ++;
            while (j >= dist && aux <= SubVetor[j - dist]) {
                SubVetor[j] = SubVetor[j - dist];
                j -= dist; // atualiza j para a posição que dista 'dist' a esquerda da posição atual
                troca++;
			    comparacoes++;
            }
            SubVetor[j] = aux;
            troca++;
        }

        dist /= 2;
    }
    return troca+comparacoes;
}
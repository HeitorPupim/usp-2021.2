#include <counting.h>

void countingSort(int *v, int numElem, int kE)
{
  int *output = malloc((numElem * sizeof(int)));
  int *count = malloc(kE * sizeof(int));
  int *pos = malloc(kE * sizeof(int));

  for (int i = 0; i < kE; i++){
    count[i] = 0;
    pos[i] = 0;
  }

  for (int i = 0; i < numElem; i++)
    count[v[i]]++;
  
  for (int i = 1; i < kE; i++)
    pos[i] = count[i - 1] + pos[i - 1];

  for (int i = 0; i < numElem; i++){
    printf("%d %d\n", v[i], pos[v[i]]);
    output[pos[v[i]]] = v[i];
    pos[v[i]]++;
  }

  for (int i = 0; i < numElem; i++)
    v[i] = output[i];
  
  free(output);
  free(count);
  free(pos);
}

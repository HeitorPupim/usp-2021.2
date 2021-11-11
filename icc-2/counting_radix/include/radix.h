#ifndef RADIX_H
#define RADIX_H

#include <util.h>

int GetNumAtual(int numAtual, int pos, int base, int numDigitos);
int countDigitos(int numAtual, int base);
void radixSort(int *v, int numElem, int base, int numDigitos);

#endif
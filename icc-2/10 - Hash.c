#include<stdio.h>
#include<stdlib.h>

void insere_elemento(int* hash, int elemento, int m)
{
	int k;
	
	for(int i = 0; i < m; i++)
	{
		k = (elemento + i) % m;
		
		if(hash[k] == -1)
		{
			hash[k] = elemento;
			break;
		}
		
		if(hash[k] == elemento)
		{
			break;
		}
		
	}
}

int busca_elemento(int* hash, int elemento, int m)
{
	int k;
	
	for(int i = 0; i < m; i++)
	{
		k = (elemento + i) % m;
		
		if(hash[k] == elemento)
		{
			hash[k] = elemento;
			return k;
		}
	}
	
	return -1;
}

int main()
{
	int m, n, d, b, elemento, *hash;
	
	scanf("%d", &m);
	hash = (int*) malloc(sizeof(int) * m);
	for(int i = 0; i < m; i++)
	{
		hash[i] = -1;
	}
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &elemento);
		insere_elemento(hash, elemento, m);
	}
	
	scanf("%d", &d);
	
	for(int i = 0; i < d; i++)
	{
		int k;
		
		scanf("%d", &elemento);
		k = busca_elemento(hash, elemento, m);
		
		if(k != -1)
		{
			hash[k] = -1;
		}
	}
	
	scanf("%d", &b);
	
	for(int i = 0; i < b; i++)
	{
		
		scanf("%d", &elemento);
		
		if(i < b-1)
		{
			printf("%d ", busca_elemento(hash, elemento, m));
		}
		else
		{
			printf("%d", busca_elemento(hash, elemento, m));
		}
	}
	
	return 0;
}




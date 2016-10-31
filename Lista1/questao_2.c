#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *v, int tam)
{
	int i;
	for(i = 0; i < tam; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int selection_sort(int *v, int tam) // retorna o numero de swaps
{
	int num_swaps = 0;
	int i, j, pos_menor;

	for(i = 0; i < tam; ++i)
	{
		pos_menor = i;
		for(j = i + 1; j < tam; ++j)
			if(v[j] < v[pos_menor])
				pos_menor = j;
		if(pos_menor != i)
		{
			swap(&v[i], &v[pos_menor]);
			++num_swaps;
		}
	}
	return num_swaps;
}

int main()
{	
	int i, tam, *v;
	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &tam);
	v = (int*) malloc(tam * sizeof(int));
	if(v == NULL)
		return -1;

	srand(time(NULL));
	for(i = 0; i < tam; ++i)
		v[i] = rand() % 100;

	printf("Vetor antes da ordenacao:\n");
	print(v, tam);
	printf("Numero de trocas: %d\n", selection_sort(v, tam));
	printf("Vetor depois da ordenacao:\n");
	print(v, tam);

	return 0;
}

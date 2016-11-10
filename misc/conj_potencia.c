#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void conj_potencia(char *arr, int arr_size)
{
	int conj_potencia_size = pow(2, arr_size);
	int i, j;

	for(i = 0; i < conj_potencia_size; ++i)
	{
		for(j = 0; j < arr_size; ++j)
			if(i & (1 << j)) // desloca bits
				printf("%c ", arr[j]);
		printf("\n");
	}
}

int main()
{
	int i, n_elementos;
	char *c;

	printf("Numero de elementos: ");
	scanf("%d", &n_elementos);

	c = (char*)malloc(n_elementos * sizeof(char));
	if(c == NULL)
		return -1;

	for(i = 0; i < n_elementos; ++i)
	{
		printf("Elemento %d: ", i + 1);
		scanf(" %c", &c[i]);
	}

	conj_potencia(c, n_elementos);
	free(c);

	return 0;
}

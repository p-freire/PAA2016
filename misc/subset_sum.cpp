#include <stdio.h>
#include <stdlib.h>

int get_index(int i, int j, int cols)
{
	return i * cols + j;
}


bool subset_sum(int *set, int n, int soma)
{
	int rows = n + 1;
	int cols = soma + 1;
	bool *matriz = new bool[rows * cols];

	// Varia nas linhas (valores do set)
	for(int i = 0; i < rows; ++i)
		matriz[get_index(i, 0, cols)] = true;

	// Varia nas colunas (valores da soma)
	for(int i = 1; i < cols; ++i)
		matriz[get_index(0, i, cols)] = false;

	for(int i = 1; i < rows; ++i)
		for(int j = 1; j < cols; ++j)
		{
			matriz[get_index(i, j, cols)] = matriz[get_index(i - 1, j, cols)];
			if(!matriz[get_index(i, j, cols)] && j >= set[i - 1])
				matriz[get_index(i, j, cols)] = matriz[get_index(i, j, cols)]
												|| matriz[get_index(i - 1, j - set[i - 1], cols)];
		}
	
	bool resultado = matriz[get_index(n, soma, cols)];
	delete [] matriz;
	return resultado;
}


int main()
{
	int n, soma, *set;

	printf("Numero de elementos: ");
	scanf("%d", &n);

	printf("Soma: ");
	scanf("%d", &soma);

	set = new int[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &set[i]);

	printf(subset_sum(set, n, soma) ? "Verdadeiro\n" : "Falso\n");

	delete [] set;
	return 0;
}
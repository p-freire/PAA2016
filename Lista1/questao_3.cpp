#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <vector>

void print(std::vector<int> a)
{
	int tam = a.size();
	for(int i = 0; i < tam; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int num_swaps(std::vector<int> a, std::vector<int> b)
{
	int contador = 0, aux = 0;
	int tam = a.size();
	for(int i = 0; i < tam; ++i)
		a[i] == b[aux] ? ++aux : ++contador;

	return contador;
}

int main()
{
	int tam;
	srand(time(NULL));

	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &tam);

	std::vector<int> v1(tam);
	std::vector<int> v2(tam);

	for(int i = 0; i < tam; ++i)
	{
		v1[i] = rand() % 100;
		//scanf("%d", &v1[i]);
		v2[i] = v1[i];
	}

	std::sort(v2.begin(), v2.end());
	printf("Vetor antes da ordenacao:\n");
	print(v1);
	printf("Vetor antes da ordenacao:\n");
	print(v2);
	printf("Numero de trocas: %d\n", num_swaps(v1, v2));

	return 0;
}

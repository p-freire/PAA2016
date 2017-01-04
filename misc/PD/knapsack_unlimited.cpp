#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>

typedef struct item
{
	int peso;
	int valor;
};


bool compare_itens(item a, item b)
{
	return a.peso < b.peso;
}

void print(std::vector<int> v)
{
	for(int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
}

int knapsack(std::vector<item> itens, int capacidade)
{
	++capacidade;
	int n_itens = itens.size();
	std::vector<int> k(capacidade, INT_MIN); // vetor de capacidades da mochila
	k[0] = 0;

	for(int i = 1; i < capacidade; ++i)
	{
		int j = 0;
		while(j < n_itens && itens[j].peso <= i)
		{
			k[i] = std::max(k[i], k[i - itens[j].peso] + itens[j].valor);
			++j;
		}
	}
	print(k);
	return k[capacidade - 1];
}


int main()
{
	int n_itens, capacidade;
	std::vector<item> itens;

	printf("Numero de itens: ");
	scanf("%d", &n_itens);

	printf("Capacidade da mochila: ");
	scanf("%d", &capacidade);

	itens.resize(n_itens);

	for(int i = 0; i < n_itens; ++i)
		scanf("%d %d", &itens[i].peso, &itens[i].valor);

	std::sort(itens.begin(), itens.end(), compare_itens);
	//print(itens);

	printf("Melhor solucao: %d\n", knapsack(itens, capacidade));

	return 0;
}
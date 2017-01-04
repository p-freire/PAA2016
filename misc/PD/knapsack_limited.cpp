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


int knapsack(std::vector<item> itens, int capacidade)
{
	int *v;
	int **tabela;
	int n_itens = itens.size() + 1;
	++capacidade;

	v = new int[capacidade * n_itens];
	tabela = new int*[capacidade + 1];
	for(int i = 0; i < capacidade; ++i)
		tabela[i] = &v[i * n_itens];

	for(int i = 0; i < capacidade; ++i)
		tabela[i][0] = 0;
	for(int i = 0; i < n_itens; ++i)
		tabela[0][i] = 0;

	for(int i = 1; i < capacidade; ++i)
	{
		for(int j = 1; j < n_itens; ++j)
			if(itens[j - 1].peso > i)
				tabela[i][j] = tabela[i][j - 1];
			else
				tabela[i][j] = std::max(tabela[i][j - 1], tabela[i - itens[j - 1].peso][j - 1] + itens[j - 1].valor);
	}	

	int maior = tabela[capacidade - 1][n_itens - 1];
	delete [] tabela;
	delete [] v;
	return maior;
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
#include <stdio.h>
#include <vector>
#include <algorithm>

typedef struct item
{
	int valor;
	int peso;
};

// ordena usando a razao entre valor e peso dos itens
bool compare_itens(item a, item b) 
{
	double r1 = (double)a.valor / a.peso;
	double r2 = (double)b.valor/ b.peso;
	return r1 > r2;
}

double mochila_fracionada(std::vector<item> itens, int capacidade)
{
	int n = itens.size();
	double valor = 0.0;
	int peso_atual = 0;
	bool flag = false; // flag usada pra quando for fracionar um item

	std::sort(itens.begin(), itens.end(), compare_itens);

	for(int i = 0; i < n && !flag; ++i)
	{
		if(peso_atual + itens[i].peso <= capacidade) // coloca o item inteiro
		{
			peso_atual += itens[i].peso;
			valor += itens[i].valor;
		}
		else // nao cabe o item inteiro, entao pega uma fracao
		{
			int espaco_sobrando = capacidade - peso_atual;
			valor += itens[i].valor * ((double)espaco_sobrando / itens[i].peso);
			flag = true; // fracionou, nao cabe mais nada; fim do algoritmo
		}
	}

	return valor;
}

int main()
{
	int n, c;
	std::vector<item> itens;

	printf("Numero de itens: ");
	scanf("%d", &n);
	itens.resize(n);

	printf("Entre com os valores na ordem [peso, valor]\n");
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &itens[i].peso, &itens[i].valor);

	printf("Capacidade da mochila: ");
	scanf("%d", &c);

	printf("O maior valor encontrado foi %.2lf\n", mochila_fracionada(itens, c));
	return 0;
}
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

int my_min(int a, int b, int c)
{
	return std::min(a, std::min(b, c));
}

int main()
{
	int n, m, maior;
	std::vector< std::vector<int> > matriz, tabela;

	printf("Dimensoes: ");
	scanf("%d %d", &n, &m);

	matriz.resize(n);
	tabela.resize(n);

	for(int i = 0; i < n; ++i)
	{
		matriz[i].resize(m);
		tabela[i].resize(m);
	}

	printf("Entre com a matriz:\n");
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &matriz[i][j]);
	
	// Casos-base
	for(int i = 0; i < n; ++i)
		tabela[i][0] = matriz[i][0];

	for(int j = 0; j < m; ++j)
		tabela[0][j] = matriz[0][j];

	// Uso de PD
	maior = INT_MIN;
	for(int i = 1; i < n; ++i)
		for(int j = 1; j < m; ++j)
			if(matriz[i][j] == 0)
				tabela[i][j] == 0;
			else
			{
				// verifica os elementos acima, na diagonal e ao lado
				tabela[i][j] = my_min(tabela[i - 1][j], tabela[i - 1][j - 1], tabela[i][j - 1]) + 1;
				maior = std::max(maior, tabela[i][j]);
			}

	printf("Dimensao da maior submatriz quadrada com valores iguais a 1: %d\n", maior);
	return 0;
}
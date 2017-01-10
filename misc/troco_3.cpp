/*
	Problema: dado um valor N e um vetor com valores de moedas, retornar
			  o numero total de formas diferentes de se formar o valor N
			  com os valores de moedas disponíveis.

	Solução: usar PD para fazer a contagem. O raciocínio é:
			 	(a) ou a moeda faz parte da solução;
			 	(b) ou a moeda NÃO faz parte da solução;
			 Somamos (a) e (b) e preenchemos uma tabela com os resultados.

			 Caso-base: 
			 			- primeira linha (valor 0) com 1 (ou seja, para 0,
			 			não temos troco a voltar - a cardinalidade do conjunto
			 			é 1 por causa do conjunto vazio).
			 			- primeira coluna com 1 também (só se tem uma forma de voltar 
			 			troco com moeda de valor 1).
			 			E sim, assume-se que sempre haverá uma moeda de valor 1.
*/


#include <stdio.h>
#include <vector>
#include <algorithm>

int conta_troco(std::vector<int> moedas, int capacidade)
{
	int n_moedas = moedas.size();
	std::vector< std::vector<int> > matriz;
	
	matriz.resize(capacidade + 1); // 0 ate n
	
	for(int i = 0; i < capacidade + 1; ++i)
		matriz[i].resize(n_moedas, 0);

	for(int i = 0; i < n_moedas; ++i)
		matriz[0][i] = 1;

	for(int i = 0; i < capacidade + 1; ++i)
		matriz[i][0] = 1;

	for(int i = 1; i < capacidade + 1; ++i)
	{
		for(int j = 1; j < n_moedas; ++j)
		{
			matriz[i][j] = (i - moedas[j] >= 0)
						   ? matriz[i - moedas[j]][j] + matriz[i][j - 1]
						   : matriz[i][j - 1];
		}
	}

	return matriz[capacidade][n_moedas - 1];
}


int main()
{
	int capacidade, n_moedas;
	std::vector<int> moedas;

	printf("Valor do troco: ");
	scanf("%d", &capacidade);

	printf("Numero de moedas: ");
	scanf("%d", &n_moedas);

	moedas.resize(n_moedas);

	for(int i = 0; i < n_moedas; ++i)
		scanf("%d", &moedas[i]);

	std::sort(moedas.begin(), moedas.end());

	printf("Formas de se voltar o troco: %d\n", conta_troco(moedas, capacidade));

	return 0;
}
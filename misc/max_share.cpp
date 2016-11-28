/*
É dado um vetor de n números inteiros representando os preços das ações de uma empresa em um único dia. 
Queremos encontrar um par (buyDay, sellDay), com buyDay ≤ sellDay, de modo que se compramos o estoque em buyDay
e vendemos em sellDay, nós maximizaríamos nosso lucro.

Exemplo do vetor:

Preços:                        3, 6, 1, 7, 2, 8, 4, 6, 9, 0, 4, 5

Onde a data está implicita iniciando-se em 0. Para este exemplo o lucro máximo é 8, comprando a ação no dia 2 custando 1
e vendendo no dia 8 valendo 9.

Claramente existe uma solução O (n²) para o algoritmo, testando todos os pares possíveis (buyDay, sellDay)
e tirando o melhor proveito de todos eles. No entanto, existe um algoritmo melhor, proponha uma solução usando divisão e conquista.

Ideia: usar o mesmo raciocínio do max_array
*/


#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm> // função max

int max_tres(int a, int b, int c)
{
	return std::max(std::max(a, b), c);
}

int maxMeio(std::vector<int> v, int e, int m, int d)
{
	int menor = INT_MAX;
	int maior = INT_MIN;

	for(int i = m; i >= e; --i)
		if(v[i] < menor)
			menor = v[i];

	for(int i = m + 1; i <= d; ++i)
		if(v[i] > maior)
			maior = v[i];

	return maior - menor;
}

int maxSub(std::vector<int> v, int e, int d)
{
	if(e == d)
		return 0;
	
	// calcula a posicao do meio
	int m = e + (d - e) / 2;

	return max_tres(maxSub(v, e, m), maxSub(v, m + 1, d), maxMeio(v, e, m ,d));
}

int main()
{
	std::vector<int> v;
	int num_elementos;

	printf("Numero de elementos: ");
	scanf("%d", &num_elementos);
	v.resize(num_elementos);

	for(int i = 0; i < num_elementos; ++i)
	{
		printf("Elemento[%d] = ", i);
		scanf("%d", &v[i]);
	}

	printf("Maior soma encontrada: %d\n", maxSub(v, 0, num_elementos - 1));

	return 0;
}

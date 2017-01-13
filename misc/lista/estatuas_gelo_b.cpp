#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#define MAX_TAM 1000010
#define MAX_BLOCOS 25

std::vector<int> blocos; // vector pra usar o std::sort
int tamanho[MAX_TAM];

int main()
{
	int t, n, m, prune;
	blocos.resize(MAX_BLOCOS);
	scanf("%d", &t);
	
	tamanho[0] = 0;
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; ++i)
			tamanho[i] = INT_MAX;

		for(int i = 0; i < n; ++i)
			scanf("%d", &blocos[i]);

		// faz um sort pra facilitar na hora de achar o maior bloco
		// se bem que eu poderia correr o vetor uma vez só pra achar isso
		// e deixar essa parte em O(n). Mas enfim...
		std::sort(blocos.begin(), blocos.end() - (MAX_BLOCOS - n));
		prune = blocos[n - 1] * blocos[n - 1];
		
		// usa DP
		for(int i = 1; i <= m; ++i)
		{
			for(int j = 0; j < n; ++j)
				if(blocos[j] <= i)
					tamanho[i] = std::min(tamanho[i], tamanho[i - blocos[j]] + 1);

			// verifica a condicao de prune
			if(i > prune && (m - i) % blocos[n - 1] == 0)
			{
				tamanho[m] = tamanho[i] + ((m - i) / blocos[n - 1]);	
				break;
			}
		}
		printf("%d\n", tamanho[m]);
	}
	return 0;
}
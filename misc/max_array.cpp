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
	int soma = 0;
	int soma_dir = INT_MIN;
	int soma_esq = INT_MIN;

	for(int i = m; i >= e; --i)
	{
		soma += v[i];
		if(soma > soma_esq)
			soma_esq = soma;
	}

	soma = 0;

	for(int i = m + 1; i <= d; ++i)
	{
		soma += v[i];
		if(soma > soma_dir)
			soma_dir = soma;
	}

	return soma_dir + soma_esq;
}

int maxSub(std::vector<int> v, int e, int d)
{
	if(e == d)
		return v[e];

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
#include <stdio.h>
#include <vector>

std::vector<int> matMul(std::vector<int> a, std::vector<int> b, int n, int m)
{
	std::vector<int> tmp(n * m, 0);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < m; ++k)
				tmp[i * m + j] += a[i * m + k] * b[j + k * n];
	return tmp;
}


std::vector<int> matPow(std::vector<int> mat, int expo, int n, int m)
{
	if(expo == 1) // caso-base
		return mat;
	else if(expo & 1) // se for ímpar
		return matMul(mat, matPow(mat, expo - 1, n, m), n, m);
	else
	{
		std::vector<int> aux = matPow(mat, expo / 2, m, n);
		return matMul(aux, aux, n, m);
	}

}


int main()
{
	std::vector<int> v, fib;
	int p;

	printf("P: ");
	scanf("%d", &p);

	if(p > 0)
	{
		v.resize(4);
		v[0] = 1; v[1] = 1; v[2] = 1; v[3] = 0;
		fib = matPow(v, p, 2, 2);
		printf("O p-esimo elemento da sequencia de Fibonacci eh %d\n", fib[2]);
	}
	else
		printf("Entre com um valor maior que zero.\n");

	return 0;
}
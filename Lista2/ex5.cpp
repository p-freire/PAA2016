#include <stdio.h>
#include <stdlib.h>
#include <vector>

double exp_num(double x, int n)
{
	if(n == 0)
		return 1.0;
	else if(n == 1)
		return x;
	else if(n & 1)
		return x * exp_num(x * x, (n - 1) / 2);
	else
		return exp_num(x * x, n / 2);
}

double pol(std::vector<double> a, double x, int n)
{
	return n == 0 ? a[0] : a[n] * exp_num(x, n) + pol(a, x, n - 1);
}


int main()
{
	std::vector<double> a;
	double x, aux;
	int n;

	printf("Numero de parcelas: ");
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
	{
		printf("Elemento %d: ", i);
		scanf("%lf", &aux);
		a.push_back(aux);
	}

	printf("Valor de X: ");
	scanf("%lf", &x);

	printf("Valor do polinomio: %.2lf\n", pol(a, x, n - 1));

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	double x;
	int n;

	printf("Valor: ");
	scanf("%lf", &x);
	printf("Expoente: ");
	scanf("%d", &n);
	printf("Resultado: %lf\n", exp_num(x, n));

	return 0;
}
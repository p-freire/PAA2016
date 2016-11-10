#include <stdio.h>
#include <stdlib.h>

unsigned long long int exp_num(int x, int n)
{
	if(n == 0)
		return 1;
	else if(n == 1)
		return x;
	else if(n & 1)
		return x * exp_num(x * x, (n - 1) / 2);
	else
		return exp_num(x * x, n / 2);
}

int main()
{
	int x, n;

	printf("Valor: ");
	scanf("%d", &x);
	printf("Expoente: ");
	scanf("%d", &n);
	printf("Resultado: %lld\n", exp_num(x, n));

	return 0;
}
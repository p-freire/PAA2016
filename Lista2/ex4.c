/*
    Esse problema é conhecido com o problema de Josephus
    Usando recursão, o problema se torna O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int josephus(int n, int k)
{
    return n == 1 ? 1 : ((josephus(n - 1, k) + k - 1) % n) + 1;
}

int main()
{
    int n, k;
    printf("Entre com o numero de pessoas e o salto: ");
    scanf("%d %d", &n, &k);
    printf("Sobrevivente: %d\n", josephus(n, k));

    return 0;
}

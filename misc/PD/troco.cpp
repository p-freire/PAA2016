#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>

int troco(std::vector<int> moedas, int valor)
{
    int s = valor + 1;
    int j;
    std::vector<int> valores(s, INT_MAX);
    valores[0] = 0;

    for(int i = 1; i < s; ++i)
    {
        j = 0;
        while(j < moedas.size() && moedas[j] <= i)
        {
            valores[i] = std::min(valores[i], valores[i - moedas[j]] + 1);
            ++j;
        }
    }
    return valores[s - 1];
}

int main()
{
    int n, valor;
    std::vector<int> v;

    printf("Numero de moedas: ");
    scanf("%d", &n);
    v.resize(n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    printf("Valor: ");
    scanf("%d", &valor);

    printf("Menor numero de moedas: %d\n", troco(v, valor));

    return 0;
}
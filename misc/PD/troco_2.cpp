#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>

int troco(std::vector<int> moedas, int valor)
{
    int s = valor + 1;
    int n_moedas = moedas.size();
    std::vector<int> valores(s, 0);
    valores[0] = 1;

    for(int i = 0; i < n_moedas; ++i)
    {
        for(int j = moedas[i]; j <= valor; ++j)
            valores[j] += valores[j - moedas[i]];
    }
    return valores[valor];
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

    printf("Numero possivel de trocos: %d\n", troco(v, valor));

    return 0;
}
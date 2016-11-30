/*
Assuma que existe um array A[1..n] com n elementos. Um elemento maioritário de A é qualquer elemento que ocorra em mais de n/2 posições (portanto, se n = 6 ou n = 7, o elemento maioritário deverá ocorrer em pelo menos 4 posições).

Assuma que os elementos não podem ser ordenados, mas podem ser comparados.

Projete um algoritmo de divisão e conquista eficiente que encontre o elemento maioritário do array A (ou determine que ele não existe) em tempo O(n log n).

*/

#include <stdio.h>
#include <limits.h>
#include <map>
#include <vector>

int main()
{
    std::map<int, int> mapa;
    std::vector<int> v;
    int n, aux = INT_MIN, maioritario;

    printf("Numero de elementos: ");
    scanf("%d", &n);

    v.resize(n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
        mapa.find(v[i]) != mapa.end() ? ++mapa[v[i]] : mapa[v[i]] = 1;
        if(mapa[v[i]] > aux)
        {
            aux = mapa[v[i]];
            maioritario = v[i];
        }
    }

    if(aux > n >> 1)
        printf("Elemento maioritario: %d\n", maioritario);
    else
        printf("Nao ha elemento maioritario.\n");
    return 0;
}

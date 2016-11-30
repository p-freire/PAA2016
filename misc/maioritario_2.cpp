/*
Assuma que existe um array A[1..n] com n elementos. Um elemento maioritário de A é qualquer elemento que ocorra em mais de n/2 posições (portanto, se n = 6 ou n = 7, o elemento maioritário deverá ocorrer em pelo menos 4 posições).

Assuma que os elementos não podem ser ordenados, mas podem ser comparados.

Projete um algoritmo de divisão e conquista eficiente que encontre o elemento maioritário do array A (ou determine que ele não existe) em tempo O(n log n).

*/

#include <stdio.h>
#include <vector>
#include <algorithm>

typedef struct maior
{
    int num;
    int rep;
};

maior conta(std::vector<int> v, int l, int meio, int r, maior a, maior b)
{
    if(a.num == b.num)
    {
        a.rep += b.rep;
        return a;
    }

    for(int i = meio; i >= l; --i)
        if(v[i] == b.num)
            ++b.rep;

    for(int i = meio + 1; i <= r; ++i)
        if(v[i] == a.num)
            ++a.rep;

    return a.rep > b.rep ? a : b;
}

maior maioritario(std::vector<int> v, int l, int r)
{
    if(r == l)
    {
        maior aux;
        aux.num = v[l];
        aux.rep = 1;
        return aux;
    }

    int meio = l + (r - l) / 2;

    maior a = maioritario(v, l, meio);
    maior b = maioritario(v, meio + 1, r);
    return conta(v, l, meio, r, a, b);
}

int main()
{
    std::vector<int> v;
    int n;

    printf("Numero de elementos: ");
    scanf("%d", &n);

    v.resize(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    maior teste = maioritario(v, 0, n - 1);

    printf("Elemento mais comum: %d com %d repeticao(oes).\n", teste.num, teste.rep);
    if(teste.rep > n >> 1)
        printf("O elemento %d eh maioritario.\n", teste.num);
    else
        printf("Nao ha elemento prioritario.\n");

    return 0;
}

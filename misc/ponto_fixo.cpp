/*
Definição: Um ponto fixo é um ponto em um vetor v, tal que v[i]=i. Por exemplo, v={1,3,2,5}, temos que v[2]=2.
Desafio: Sabendo que o vetor v está sempre em ordem crescente e com no máximo um ponto fixo,
fazer um algoritmo usando divisão e conquista que dado um vetor v,
retorna o seu ponto fixo i, ou -1 caso não haja um ponto fixo e diga sua complexidade.
*/

#include <stdio.h>
#include <vector>

int buscaBin(std::vector<int> v, int l, int r)
{
    int m;

    while(l <= r)
    {
        m = l + (r - l) / 2;
        if(v[m] == m)
            return m;
        else if(v[m] > m)
            r = m - 1;
        else
            l = m + 1;
    }

    return -1;
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

    int res = buscaBin(v, 0, n - 1);
    if(res == -1)
        printf("Nao encontrado.\n");
    else
        printf("O elemento %d eh fixo.\n", res);

    return 0;
}

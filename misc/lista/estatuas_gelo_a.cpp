#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define MAX_SIZE 1000010
#define MAX_BLOCOS 25

int tamanho[MAX_SIZE];
int blocos[MAX_BLOCOS];

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; ++i)
            tamanho[i] = INT_MAX;
        tamanho[0] = 0;

        for(int i = 0; i < n; ++i)
            scanf("%d", &blocos[i]);

        for(int i = 1; i <= m; ++i)
            for(int j = 0; j < n; ++j)
                if(blocos[j] <= i)
                    tamanho[i] = std::min(tamanho[i], tamanho[i - blocos[j]] + 1);
        printf("%d\n", tamanho[m]);
    }

    return 0;
}

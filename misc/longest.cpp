#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <algorithm>

void print(std::vector<int> v)
{
    for(int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int longest(std::vector<int> v)
{
    int s = v.size();
    int longest_sum = INT_MIN;
    std::vector<int> aux(s, 0);

    aux[0] = v[0];
    for(int i = 1; i < s; ++i)
        aux[i] = aux[i - 1] + v[i] >= v[i] ? aux[i - 1] + v[i] : v[i];

    for(int i = 0; i < s; ++i)
        longest_sum = std::max(longest_sum, aux[i]);
    return longest_sum;
}

int main()
{
    int n;
    std::vector<int> v;

    printf("Numero de elementos: ");
    scanf("%d", &n);
    v.resize(n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    printf("Maior soma: %d\n", longest(v));
    return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

int lis(std::vector<int> &v)
{
    int s = v.size();
    std::vector<int> table(s, 1);
    int max_lis = 1;

    for(int i = 1; i < s; ++i)
    {
        int j = 0;
        while(j < i)
        {
            if(v[j] < v[i])
            {
                table[i] = std::max(table[i], table[j] + 1);
                max_lis = std::max(max_lis, table[i]);
            }
            ++j;
        }
    }
    return max_lis;
}

int main()
{
    std::vector<int> v;
    int n;

    printf("Number of elements: ");
    scanf("%d", &n);

    v.resize(n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    printf("LIS = %d\n", lis(v));

    return 0;
}

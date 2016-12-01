#include <iostream>
#include <stdio.h>
#include <vector>

void print(std::vector<int> v)
{
    int s = v.size();
    for(int i = 0; i < s; ++i)
        printf("%d ", v[i]);
    printf("\n");
}


std::vector<int> merger(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> aux;
    int size_a = a.size();
    int size_b = b.size();
    int i = 0, j = 0;

    while(i < size_a && j < size_b)
    {
        if(a[i] < b[j])
            aux.push_back(a[i++]);
        else
            aux.push_back(b[j++]);
    }

    while(i < size_a)
        aux.push_back(a[i++]);
    while(j < size_b)
        aux.push_back(b[j++]);

    return aux;
}


std::vector<int> sorter(std::vector<int> v)
{
    if(v.size() == 1)
        return v;

    int middle = (v.size() - 1) / 2;
    std::vector<int> a;
    std::vector<int> b;

    for(int i = 0; i <= middle; ++i)
        a.push_back(v[i]);
    for(int i = middle + 1; i < v.size(); ++i)
        b.push_back(v[i]);

    return merger(sorter(a), sorter(b));
}


int main()
{
    std::vector<int> arr;
    std::vector<int> res;
    int n;

    scanf("%d", &n);
    arr.resize(n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    print(arr);
    res = sorter(arr);
    print(res);
    return 0;
}

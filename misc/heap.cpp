#include <stdio.h>
#include <vector>
#include <time.h>

void print(std::vector<int> v)
{
    int s = v.size();
    for(int i = 0; i < s; ++i)
        printf("%d ", v[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(std::vector<int> &v, int pos, int s)
{
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    int max_pos = pos;

    if(l < s && v[l] > v[max_pos])
        max_pos = l;
    if(r < s && v[r] > v[max_pos])
        max_pos = r;
    if(max_pos != pos)
    {
        swap(&v[pos], &v[max_pos]);
        heapify(v, max_pos, s);
    }
}

void heapsort(std::vector<int> &v, int n)
{
    while(n > 0)
    {
        swap(&v[0], &v[n - 1]);
        --n;
        heapify(v, 0, n);
    }
}

int main()
{
    std::vector<int> v;
    int n;
    srand(time(NULL));

    scanf("%d", &n);
    v.resize(n);

    for(int i = 0; i < n; ++i)
        v[i] = rand() % 50;
        //scanf("%d", &v[i]);

    printf("Original:\n");
    print(v);

    for(int i = n / 2 - 1; i >= 0; --i)
        heapify(v, i, n);

    printf("Heapified:\n");
    print(v);

    heapsort(v, n);
    printf("Heapsorted:\n");
    print(v);

    return 0;
}

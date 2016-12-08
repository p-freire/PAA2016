#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

int bin_search(std::vector<int> v, int l, int r, int key)
{
	int middle;
	while(l <= r)
	{
		middle = l + (r - l) / 2;
		if(v[middle] == key)
			return middle;
		else if(key > v[middle])
			l = middle + 1;
		else 
			r = middle - 1;
	}
	return INT_MIN;
}

int main()
{
	int n, key, ans;
	std::vector<int> v;

	printf("Numero de elementos: ");
	scanf("%d", &n);

	v.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	std::sort(v.begin(), v.end());

	printf("Elemento a ser buscado: ");
	scanf("%d", &key);

	ans = bin_search(v, 0, n - 1, key);

	if(ans != INT_MIN)
		printf("Elemento encontrado! Posicao: %d.\n", ans);
	else
		printf("Elemento nao encontrado.\n");

	return 0;
}
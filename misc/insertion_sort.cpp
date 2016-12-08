#include <stdio.h>
#include <vector>

void print(std::vector<int> v, int n)
{
	for(int i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");
}


void insertion(std::vector<int> &v, int n)
{
	int temp, j;

	for(int i = 1; i < n; ++i)
	{
		temp = v[i];
		j = i - 1;

		while(j >= 0 && v[j] > temp)
		{	
			v[j + 1] = v[j];
			--j;
		}
		
		if(j != i - 1)
		{
			j = j >= 0 ? j + 1 : 0;
			v[j] = temp;
		}
	}
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

	print(v, n);
	insertion(v, n);
	print(v, n);

	return 0;
}
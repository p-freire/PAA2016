#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void power_set(char *arr, int arr_size)
{
	int power_set_size = pow(2, arr_size);

	for(int i = 0; i < power_set_size; ++i)
	{
		for(int j = 0; j < arr_size; ++j)
			if(i & (1 << j))
				printf("%c ", arr[j]);
		printf("\n");
	}
}

int main()
{
	int n_elements;
	char *c;

	printf("Number of elements: ");
	scanf("%d", &n_elements);

	c = (char*)malloc(n_elements * sizeof(char));

	for(int i = 0; i < n_elements; ++i)
	{
		printf("Element %d: ", i + 1);
		scanf(" %c", &c[i]);
	}

	power_set(c, n_elements);

	return 0;
}
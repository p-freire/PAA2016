#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::vector<int> num, states;

	printf("N: ");
	scanf("%d", &n);
	num.resize(n);
	states.resize(n);

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &num[i]);
		states[i] = INT_MIN;
	}

	states[0] = 1;
	for(int i = 1; i < n; ++i)
		states[i] = num[i] > num[i - 1]
				    ? states[i] = std::max(states[i], states[i - 1] + 1)
				    : states[i] = states[i - 1];

	printf("LIS: %d\n", states[n - 1]);
	return 0;
}
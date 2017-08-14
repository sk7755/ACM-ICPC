#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	
	int k;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		k = i;
		if (k >n - 1)
			k = 2 * n - 2 - i;
		for (int j = 0; j <= k; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}
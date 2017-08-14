#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 2 * n - 1; i++)
	{
		int k = i;

		if (k > n - 1)
			k = 2 * n - 2 - k;

		for (int j = 0; j < n; j++)
		{
			if (j < n - k - 1)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}
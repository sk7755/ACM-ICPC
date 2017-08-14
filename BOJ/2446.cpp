#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < 2 * n - 1; i++)
	{
		int k = i;
		if (i > n - 1)
			k = 2 * (n - 1) - i;

		for (int j = 0; j < 2 * n - 1 - k; j++)
		{
			if (j < k)
				printf(" ");
			else
				printf("*");
		}

		printf("\n");
	}

	return 0;
}
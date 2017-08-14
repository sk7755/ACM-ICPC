#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + i; j++)
		{
			if (j < n - 1 - i)
				printf(" ");
			else
			{
				if ((j - n + i) % 2)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
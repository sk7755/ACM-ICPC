#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1 + i % 2; j++)
		{
			if ((j + i % 2) % 2)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
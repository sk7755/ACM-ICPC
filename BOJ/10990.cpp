#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + n; j++)
		{
			if (j == n - 1-i || j == i + n - 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
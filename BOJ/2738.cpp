#include <cstdio>

int main()
{
	int matrix[100][100] = { 0, };

	int n, m;
	scanf("%d %d", &n, &m);

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int temp;
				scanf("%d", &temp);
				matrix[i][j] += temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	return 0;
}
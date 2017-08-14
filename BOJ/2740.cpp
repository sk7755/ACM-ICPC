#include <cstdio>

int main()
{
	int A[100][100];
	int B[100][100];
	int C[100][100] = { 0, };

	int n, m, k;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	}

	scanf("%d %d", &m, &k);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
			scanf("%d", &B[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int r = 0; r < m; r++)
				C[i][j] += A[i][r] * B[r][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}
#include <cstdio>

struct mat
{
	int r, c;
};

int main()
{
	int dp[500][500] = { 0, };
	mat matrix[500];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &matrix[i].r, &matrix[i].c);
	}

	for (int l = 1; l < n; l++)
	{
		for (int i = 0; i < n-l; i++)
		{
			int j = l + i;

			int min = 0x7fffffff;
			for (int k = i; k < j; k++)
			{
				int tmp = dp[i][k] + dp[k + 1][j] + matrix[i].r * matrix[k].c * matrix[j].c;

				if (min > tmp)
					min = tmp;
			}

			dp[i][j] = min;
		}
	}

	printf("%d\n", dp[0][n - 1]);

	return 0;
}
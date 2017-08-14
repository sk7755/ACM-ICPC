#include <cstdio>

int main()
{
	int dp[101][30] = { 0, };
	int n,m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 30; j++)
			dp[0][j] = dp[i][j] = 0;
		dp[0][29] = dp[i][29] = 1;

		int temp[30];

		for (int j = 0; j < 30; j++)
			temp[j] = dp[0][j];

		for (int j = 1; j < i ; j++)
		{
			int temp2[30];
			for (int k = 0; k < 30; k++)
				temp2[k] = dp[j][k];

			int carry = 0;
			for (int k = 29; k >=0; k--)
			{
				dp[j][k] = temp[k] + dp[j][k] + carry;
				if (dp[j][k]>9)
					carry = 1, dp[j][k] -= 10;
				else
					carry = 0;
			}

			for (int k = 0; k < 30; k++)
				temp[k] = temp2[k];
		}
	}
	for (int i = 0; i < 30; i++)
	{
		if (dp[m][i])
		{
			for (; i < 30; i++)
				printf("%d", dp[m][i]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}

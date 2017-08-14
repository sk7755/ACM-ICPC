#include <cstdio>

int main()
{
	int n;
	int a[2001];
	int dp[2001][2001] = { 0, };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i - 1; j++)
		{
			if (a[i] == a[j] && dp[i - 1][j + 1])
				dp[i][j] = 1;
		}
		if (a[i] == a[i - 1])
			dp[i][i - 1] = 1;
		dp[i][i] = 1;
	}

	int m;
	scanf("%d", &m);

	char str[2000001];
	int k = 0;

	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		str[k++] = dp[end][start] + '0';
		str[k++] = '\n';
	}
	str[k++] = '\0';

	printf("%s", str);

	return 0;
}
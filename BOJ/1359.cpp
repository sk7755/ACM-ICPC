#include <cstdio>

int main()
{
	int c[9][9] = { 0, };

	for (int i = 1; i < 9; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 2; i < 9; i++)
	{
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	long long denominator = c[n][m];
	long long nominator = 0;

	for (int i = k; i <= m; i++)
		nominator += c[m][i] * c[n-m][m-i];


	printf("%lld.%09lld\n", nominator / denominator, nominator % denominator * 1000000000 / denominator);

	return 0;
}

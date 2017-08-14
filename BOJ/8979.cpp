#include <cstdio>

int main()
{
	int a[1001][3] = { 0, };

	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);

		for (int j = 0; j < 3; j++)
			scanf("%d", &a[m][j]);
	}

	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[k][j] < a[i][j])
			{
				ans++;
				break;
			}
			else if (a[k][j] > a[i][j])
				break;
		}
	}

	printf("%d\n", ans);

	return 0;
}
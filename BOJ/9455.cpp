#include <cstdio>

int main()
{
	int g[100][100];

	int t;

	scanf("%d", &t);

	while (t--)
	{
		int m, n;

		scanf("%d %d", &m, &n);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &g[i][j]);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			//dis�� �󸶳� �������ִ���
			//pre�� ���� ���� �󸶳� ���� �̵��ߴ���
			int k=0, pre=0;
			for (int j = m - 1; j >= 0; j--)
			{
				if (g[j][i])
				{
					ans += k + pre;
					pre = k + pre;
					k = -1;
				}
				k++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
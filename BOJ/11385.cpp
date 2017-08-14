#include <cstdio>

int main()
{
	long long a[1000001];
	long long b[1000001];
	long long c[2000001] = { 0, };

	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i <= m; i++)
	{
		scanf("%lld", &b[i]);
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			c[i + j] += a[i] * b[j];
		}
	}

	long long ans = c[0];
	for (int i = 1; i <= m + n; i++)
	{
		ans = ans^c[i];
	}

	printf("%lld\n", ans);

	return 0;
}
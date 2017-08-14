#include <cstdio>

int main()
{
	int n;
	int sum[100000] = { 0, };
	scanf("%d", &n);

	int m;
	for (m = 1;; m++)
	{
		sum[m] = sum[m - 1] + m;
		if (sum[m] > n)
			break;
	}

	int ans = 0;
	for (m = m-1; m > 0 && n; m--)
	{
		if (sum[m] <= n)
			n -= sum[m], ans += m;
	}
	if (n)
		ans++;
	printf("%d\n", ans);
	

	return 0;
}
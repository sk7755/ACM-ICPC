#include <cstdio>

int slope_cmp(long long b, long long a, long long d, long long c);

int main()
{
	int n;
	scanf("%d", &n);

	long long h[50];

	for (int i = 0; i < n; i++)
		scanf("%lld", &h[i]);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		long long a, b, c, d;
		int cnt = 0;
		//기울기 최하로 초기화
		a = 1;
		b = -1000000000;
		for (int j = i+1; j < n; j++)
		{
			c = j - i;
			d = h[j] - h[i];

			if (slope_cmp(b, a, d, c) < 0)
			{
				cnt++;
				a = c, b = d;
			}
		}
		a = 1;
		b = 1000000000;
		for (int j = i - 1; j >= 0; j--)
		{
			c = i - j;
			d = h[i] - h[j];

			if (slope_cmp(b, a, d, c) > 0)
			{
				cnt++;
				a = c, b = d;
			}
		}
		if (cnt > ans)
			ans = cnt;
	}
	printf("%d\n", ans);
}

int slope_cmp(long long b, long long a, long long d, long long c)
{
	if (b*c > a*d)
		return 1;
	else if (b*c < a*d)
		return -1;
	else
		return 0;
}
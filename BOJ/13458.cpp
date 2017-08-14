#include <cstdio>

int main()
{
	int n;
	long long a[1000000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	long long b, c;
	scanf("%lld %lld", &b, &c);

	long long ans = n;

	for (int i = 0; i < n; i++)
	{
		if (a[i] - b > 0)
		{
			ans += (a[i] - b) / c;
			if ((a[i] - b) % c)
				ans++;
		}
	}
	

	printf("%lld\n", ans);
}
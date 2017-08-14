#include <cstdio>

int main()
{
	long long x, y;

	while (scanf("%lld %lld", &x, &y) == 2)
	{
		long long z = (100 * y) / x;
		long long r = (100 * y) % x;
		if (z >= 99)
		{
			printf("-1\n");
			continue;
		}

		long long ans = (x - r) / (99 - z);
		if ((x - r) % (99 - z))
			ans++;

		printf("%lld\n", ans);
	}
	return 0;
}
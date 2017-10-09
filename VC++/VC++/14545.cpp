#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		long long n;
		scanf("%lld", &n);

		long long ans = n*(n + 1) / 2;

		if (ans % 3)
			ans *= (2 * n + 1) / 3;
		else
			ans = ans / 3 * (2 * n + 1);
	
		printf("%lld\n", ans);
	}

	return 0;
}
#include <cstdio>

int main()
{
	int n, k;

	while (scanf("%d %d", &n, &k) == 2)
	{
		int ans = n;

		while (n >= k)
		{
			int tmp = n / k;
			ans += tmp;
			n %= k;
			n += tmp;
		}
		printf("%d\n", ans);
	}
}
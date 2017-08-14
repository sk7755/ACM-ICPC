#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int ans = 0;
	for (int i = 1; i*i <= n; i++)
	{
		int h = n / i;

		if (h - i + 1 > 0)
			ans += h - i + 1;
	}
	printf("%d\n", ans);
}
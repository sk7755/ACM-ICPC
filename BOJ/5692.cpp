#include <cstdio>

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			return 0;

		int ans = 0;
		int k = 1;
		int i = 1;
		while (n)
		{
			k *= i++;
			ans += (n % 10) * k;
			n /= 10;
		}
		printf("%d\n", ans);
	}
}
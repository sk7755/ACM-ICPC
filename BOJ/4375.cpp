#include <cstdio>

int main()
{
	int n;
	while (scanf("%d",&n) == 1)
	{
		if (n == 1)
		{
			printf("%d\n", 1);
			continue;
		}

		int lhs = 1;
		int power = 1;
		int ans = 1;
		while (lhs)
		{
			power *= 10;
			power %= n;
			lhs = (lhs + power) % n;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
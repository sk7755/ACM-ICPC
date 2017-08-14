#include <cstdio>

int main()
{

	int t;

	scanf("%d", &t);

	while (t--)
	{

		int a, b;

		scanf("%d %d", &a, &b);

		long long ans = a;
		ans *= b;

		if (b > a)
		{
			int temp = b;
			b = a;
			a = temp;
		}

		while (b)
		{
			a %= b;
			int temp = a;
			a = b;
			b = temp;
		}

		ans /= a;

		printf("%lld\n", ans);
	}
	return 0;
}
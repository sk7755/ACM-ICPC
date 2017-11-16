#include <cstdio>

enum{ m = 987654321};

int main()
{
	int num[1000000] = { 0, };
	long long ans = 1;

	for (int i = 2; i < 1000; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j < 1000000; j += i)
			{
				num[j] = 1;
			}
		}
	}

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		if (!num[i])
		{
			int tmp = n/i;
			while (tmp)
			{
				tmp /= i;
				ans = (ans* i)%m;
			}
		}
	}

	printf("%lld\n", ans);
}
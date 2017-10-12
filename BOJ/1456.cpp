#include <cstdio>

int main()
{
	bool num[10000001] = { 0, };
	for (int i = 2; i < 10000; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j <= 10000000; j += i)
				num[j] = 1;
		}
	}

	long long a, b;

	scanf("%lld %lld", &a, &b);

	int ans = 0;
	for (long long i = 2; i <= 10000000; i++)
	{
		if (!num[i])
		{
			long long p = i*i;
			while (true)
			{
				if(a <= p && p <= b)
					ans++;
				if (p > b / i)
					break;
				p *= i;
			}
		}
	}

	printf("%d\n", ans);
}
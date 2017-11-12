#include <cstdio>

int main()
{
	bool num[1000000] = { 0, };
	long long prime[100000] = { 0, };
	int n=0;

	for (int i = 2; i < 1000; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j < 1000000; j += i)
				num[j] = 1;
		}
	}
	for (int i = 2; i < 1000000; i++)
	{
		if (!num[i])
			prime[n++] = i;
	}
	int t;
	scanf("%d", &t);

	while (t--)
	{
		long long m;
		scanf("%lld", &m);
		int success = 1;
		for (int i = 0; i < n; i++)
		{
			if (!(m%prime[i]))
			{
				success = 0;
				break;
			}
		}
		if (success)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
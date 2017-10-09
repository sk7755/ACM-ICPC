#include <cstdio>

int main()
{
	bool num[100001] = { 0, };

	for (int i = 2; i <= 333; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j <= 100000; j += i)
				num[j] = 1;
		}
	}

	bool num2[100001] = { 0, };

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = k + 1; i <= n; i++)
	{
		if (!num[i])
		{
			for (int j = i; j <= n; j += i)
				num2[j] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!num2[i])
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
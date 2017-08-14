#include <cstdio>

int main()
{
	int num[10001] = { 0, };

	for (int i = 2; i <= 100; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j <= 10000; j += i)
				num[j] = 1;
		}
	}

	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = n / 2; i >= 2; i--)
		{
			int j = n - i;

			if (!num[i] && !num[j])
			{
				printf("%d %d\n", i, j);
				break;
			}
		}
	}

	return 0;
}
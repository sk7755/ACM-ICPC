#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int op;

	scanf("%d", &op);

	long long f = 1;
	for (int i = 2; i <= n; i++)
		f *= (long long)i;

	int num[20];
	for (int i = 0; i < n; i++)
		num[i] = i+1;

	if (op == 1)
	{
		long long order;
		scanf("%lld", &order);
		order--;
		for (int i = 1; i <= n; i++)
		{
			f /= (long long)(n - i + 1);
			int k = order / f;
			printf("%d ", num[k]);

			for (int j = k; j < n-i; j++)
				num[j] = num[j + 1];
			order %= f;
		}
	}
	else
	{
		long long ans = 1;
		for (int i = 0; i < n; i++)
		{
			int target;
			scanf("%d", &target);

			f /= (long long)(n - i);
			
			int j;
			for (j = 0; j < n; j++)
			{
				if (num[j] == target)
					break;
			}
			ans += (long long)j*f;

			for (; j < n - i-1; j++)
				num[j] = num[j + 1];
		}
		printf("%lld\n", ans);
	}
}
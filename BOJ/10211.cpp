#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		int ans = -1000000000;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (sum < 0)
				sum = tmp;
			else
				sum += tmp;

			if (sum > ans)
				ans = sum;
		}
		printf("%d\n", ans);
	}

	return 0;
}
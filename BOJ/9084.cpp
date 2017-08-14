#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		int a[20];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int dp[10001] = { 1,0 };

		int price;
		scanf("%d", &price);

		for (int i = 0; i < n; i++)
		{
			for (int j = a[i]; j <= price; j++)
			{
				dp[j] += dp[j - a[i]];
			}
		}

		printf("%d\n", dp[price]);
	}

	return 0;
}
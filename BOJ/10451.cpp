#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	int a[1001] = { 0, };

	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i])
			{
				int cur = i;
				while (a[cur])
				{
					int temp = a[cur];
					a[cur] = 0;
					cur = temp;
				}
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
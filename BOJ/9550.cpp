#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			ans += tmp / k;
		}
		printf("%d\n", ans);
	}
}
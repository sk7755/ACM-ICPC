#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int p, m;
		int a[501] = { 0, };
		scanf("%d %d", &p, &m);

		int ans = 0;
		for (int i = 0; i < p; i++)
		{
			int tmp;
			scanf("%d", &tmp);

			if (a[tmp])
				ans++;
			else
				a[tmp] = 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
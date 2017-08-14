#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (!((i*i + j*j + m) % (i*j)))
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
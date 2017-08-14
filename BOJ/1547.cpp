#include <cstdio>

int main()
{
	int m;
	int ans = 1;

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == ans)
		{
			ans = b;
		}
		else if (b == ans)
		{
			ans = a;
		}
	}
	printf("%d\n", ans);
}
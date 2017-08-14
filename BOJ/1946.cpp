#include <cstdio>

int main()
{
	int a[100001];
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);
		int g1, g2;
		for (int i = 0; i < n; i++)
			scanf("%d %d",&g1,&g2), a[g1] = g2;

		int pre = a[1];
		int hire = 1;
		for (int i = 2; i <= n; i++)
		{
			if (pre > a[i])
			{
				hire++;
				pre = a[i];
			}
		}

		printf("%d\n", hire);
		
	}
	return 0;
}

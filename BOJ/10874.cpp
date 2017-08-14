#include <cstdio>

int main()
{
	int n;
	int a[11];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 10; j++)
			scanf("%d", &a[j]);

		int flag = 1;
		for (int j = 1; j <= 10; j++)
		{
			if (a[j] != (j-1)%5+1)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d\n", i);
	}
	return 0;
}
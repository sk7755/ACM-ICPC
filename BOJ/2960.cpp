#include <cstdio>

int main()
{
	int num[1001] = { 0, };
	int n, k;

	scanf("%d %d", &n, &k);

	int del = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!num[i])
		{
			for (int j = i; j <= n; j+=i)
			{
				if (!num[j])
				{
					del++;

					num[j] = 1;

					if (del == k)
					{
						printf("%d\n", j);
						return 0;
					}
				}
			}
		}
	}
}
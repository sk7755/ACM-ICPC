#include <cstdio>

int num[1000] = { 0, };
int prime[300];
int k = 0;

int ans(int n);

int main()
{

	for (int i = 2; i < 32; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j < 1000; j += i)
				num[j] = 1;
		}
	}

	for (int i = 2; i < 1000; i++)
	{
		if (!num[i])
			prime[k++] = i;
	}

	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;

		scanf("%d", &n);
		if (!ans(n))
			printf("0\n");
	}
}

int ans(int n)
{
	for (int i = 0;i<k; i++)
	{
		for (int j = i; j < k; j++)
		{
			for (int l = j; l < k; l++)
			{
				if (prime[i] + prime[j] + prime[l] == n)
				{
					printf("%d %d %d\n", prime[i], prime[j], prime[l]);
					return 1;
				}
			}
		}
	}
	return 0;
}
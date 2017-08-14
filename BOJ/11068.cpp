#include <cstdio>

int isFel(int n, int b);

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		int flag = 0;
		for (int i = 2; i <= 64; i++)
		{
			if (isFel(n, i))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}

int a[32];

int isFel(int n, int b)
{
	int k = 0;
	while (n)
	{
		a[k++] = n%b;
		n /= b;
	}

	for (int i = 0; i < k/2; i++)
	{
		if (a[i] != a[k - 1 - i])
			return 0;
	}

	return 1;
}
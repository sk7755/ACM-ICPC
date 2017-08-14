#include <cstdio>

int power(int a, int n);

int main()
{
	int a, p;
	int mark[300000] = { 0, };

	scanf("%d %d", &a, &p);

	for (int i = 1;; i++)
	{
		if (mark[a])
		{
			printf("%d\n",mark[a]-1);
			return 0;
		}
		else
			mark[a] = i;

		int tmp = 0;
		while (a)
		{
			tmp += power(a % 10, p);
			a /= 10;
		}
		a = tmp;
	}
}

int power(int a, int n)
{
	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		ret *= a;
	}

	return ret;
}
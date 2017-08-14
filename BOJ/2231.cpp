#include <cstdio>

int oper(int n);

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = n - 63; i < n;i++)
	{
		if (i >= 1 && oper(i) == n)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}

int oper(int n)
{
	int tmp = n;

	while (tmp)
	{
		n += tmp % 10;
		tmp /= 10;
	}
	return n;
}
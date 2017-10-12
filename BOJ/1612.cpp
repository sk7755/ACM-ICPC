#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	if (!(n % 2))
	{
		printf("-1\n");
		return 0;
	}
	int res = 1 % n;
	int pow = 1;
	for(int i = 1;i<=n;i++)
	{
		if (!res)
		{
			printf("%d\n", i);
			return 0;
		}
		pow = (pow * 10) % n;
		res = (res + pow) % n;
	}
	printf("-1\n");
	return 0;
}
#include <cstdio>


int main()
{
	int n;

	scanf("%d", &n);

	if (n == 0)
	{
		printf("0\n0\n");
		return 0;
	}

	if (n < 0)
	{
		n = -n;

		if (n % 2)
			printf("1\n");
		else
			printf("-1\n");
	}
	else
		printf("1\n");

	int a[2] = { 0, 1 };
	int pre = 0, cur = 1;

	for (int i = 2; i <= n; i++)
		a[pre] += a[cur], a[pre]%=1000000000, pre^=1, cur^=1;
	printf("%d\n", a[cur]);

}
#include <cstdio>

int main()
{
	int k, n, m;

	scanf("%d %d %d", &k, &n, &m);

	int money = k*n - m;
	if (money >= 0)
		printf("%d\n", money);
	else
		printf("0\n");

	return 0;
}
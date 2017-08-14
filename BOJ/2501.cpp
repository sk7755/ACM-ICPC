#include <cstdio>

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!(n%i))
			m++;
		if (m == k)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");

	return 0;
}
#include <cstdio>

int main()
{
	long long n;
	int L;

	scanf("%lld %d", &n, &L);

	int i, a;
	for (i = L; i <= 100; i++)
	{
		if (!((2 * n - i*i + i) % (2 * i)))
		{
			a = (2 * n - i*i + i) / (2 * i);
			break;
		}
	}

	if (i > 100 || a < 0)
		printf("-1\n");
	else
	{
		for (int j = 0; j < i; j++)
		{
			printf("%d ", a + j);
		}
		printf("\n");
	}

	return 0;

}
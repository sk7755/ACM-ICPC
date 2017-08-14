#include <cstdio>

int main()
{
	int n;
	int max = 0;

	scanf("%d", &n);

	int a;
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);

		sum += a;
		if (a>max)
			max = a;
	}

	printf("%.2lf\n",sum * 100 / max / n);

	return 0;
}
#include <cstdio>

int main()
{
	double a[3];
	for (int i = 0; i < 3; i++)
		scanf("%lf", &a[i]);

	double b[3];
	for (int i = 0; i < 3; i++)
		scanf("%lf", &b[i]);

	double min = 5000;

	for (int i = 0; i < 3; i++)
	{
		if (min > a[i] / b[i])
			min = a[i] / b[i];
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%lf ", a[i] - min*b[i]);
	}

	return 0;
}
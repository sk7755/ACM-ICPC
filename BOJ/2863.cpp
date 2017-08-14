#include <cstdio>

int main()
{
	double a[4];

	for (int i = 0; i < 4; i++)
		scanf("%lf", &a[i]);
	double tmp = a[2];
	a[2] = a[3];
	a[3] = tmp;

	double max = a[0] / a[3] + a[1] / a[2];
	int ans = 0;

	for (int i = 1; i <= 3; i++)
	{
		double tmp = a[3];
		for (int j = 3; j>0; j--)
			a[j] = a[j - 1];
		a[0] = tmp;
		if (a[0] / a[3] + a[1] / a[2] > max)
			max = a[0] / a[3] + a[1] / a[2], ans = i;
	}
	printf("%d\n", ans);

	return 0;

}
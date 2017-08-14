#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	double m = 1;
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		double temp;
		scanf("%lf", &temp);

		if (m < 1)
			m = temp;
		else
			m *= temp;

		if (m > ans)
			ans = m;
	}

	printf("%.3lf\n", ans);
}
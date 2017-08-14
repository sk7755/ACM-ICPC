#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		double d;
		scanf("%d %lf", &n, &d);

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			double v, f, c;
			scanf("%lf %lf %lf", &v, &f, &c);
			if (d / v <= f / c)
				ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}
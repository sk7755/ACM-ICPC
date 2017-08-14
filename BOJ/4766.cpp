#include <cstdio>

int main()
{
	double pre;

	scanf("%lf", &pre);
	while (true)
	{
		double t;

		scanf("%lf", &t);

		if (t == 999)
			return 0;

		printf("%.2lf\n", t - pre);
		pre = t;
	}
	return 0;
}
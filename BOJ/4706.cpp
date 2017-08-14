#include <cstdio>
#include <cmath>

int main()
{
	while (true)
	{
		double a, b;
		scanf("%lf %lf", &a, &b);

		if (a == 0 && b == 0)
			return 0;

		printf("%.3lf\n",sqrt(1 - (b / a)*(b / a)));
	}
}
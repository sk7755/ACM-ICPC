#include <cmath>
#include <cstdio>

int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	double k = a*b;
	k = sqrt(k);

	printf("%.3lf %.3lf\n", k, k);

	return 0;
}
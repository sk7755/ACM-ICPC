#include <cstdio>
#include <cmath>

int main()
{
	double a, b, l;

	scanf("%lf %lf %lf", &l, &a, &b);

	double k = (l*l) / (a*a + b*b);

	k = sqrt(k);

	printf("%d %d\n", (int)(a*k),(int)(b*k));

	return 0;
}
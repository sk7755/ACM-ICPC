#include <cstdio>

int main()
{
	double pi = 3.14159265358979323846;

	double r;
	scanf("%lf", &r);

	r*=r;
	printf("%lf\n%lf\n", pi*r, r * 2);

	return 0;
}
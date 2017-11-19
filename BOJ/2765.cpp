#include <cstdio>

int main()
{
	double diameter, rotation, time;
	double pi = 3.14159265358979;
	double k = 0.0000157828283;
	for (int t = 1;; t++)
	{
		scanf("%lf %lf %lf", &diameter, &rotation, &time);

		if (rotation == 0)
			return 0;
		printf("Trip #%d: %.2lf %.2lf\n", t,diameter*pi*rotation * k , diameter*pi*rotation* k / (time/3600));

	}
}
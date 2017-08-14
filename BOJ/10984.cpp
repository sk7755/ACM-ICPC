#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		int c;
		int entire_c = 0;
		double g;
		double cgpa = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%d %lf", &c, &g);
			entire_c += c;
			cgpa += + g * c;
		}

		printf("%d %.1lf\n", entire_c, cgpa/entire_c);
	}

	return 0;
}
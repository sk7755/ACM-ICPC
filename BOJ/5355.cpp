#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		char c;
		double a;
		scanf("%lf", &a);
		while ((c = getchar()) != '\n')
		{
			if (c == '@')
				a *= 3;
			else if (c == '%')
				a += 5;
			else if (c == '#')
				a -= 7;
		}

		printf("%.2lf\n", a);
	}

	return 0;
}
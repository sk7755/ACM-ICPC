#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		double a;
		scanf("%lf", &a);
		char str[10];
		scanf("%s", str);

		if (str[0] == 'k')
			printf("%.4lf lb\n",a * 2.2046);
		else if (str[0] == 'l')
		{
			if (str[1] == 'b')
				printf("%.4lf kg\n",a* 0.4536);
			else
				printf("%.4lf g\n", a *0.2642);
		}
		else
			printf("%.4lf l\n",a* 3.7854);
	}
}
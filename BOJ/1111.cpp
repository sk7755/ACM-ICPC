#include <cstdio>

int main()
{
	int x[50];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	if (n == 1)
	{
		printf("A\n");
	}
	else if (n == 2)
	{
		if (x[0] == x[1])
			printf("%d\n",x[0]);
		else
			printf("A\n");
	}
	else
	{
		int a, b;
		if (x[0] == x[1])
			a = 1, b = 0;
		else if ((x[1] - x[2]) % (x[0] - x[1]))
		{
			printf("B\n");
			return 0;
		}
		else
		{
			a = (x[1] - x[2]) / (x[0] - x[1]);
			b = x[1] - a*x[0];
		}
		for (int i = 2; i < n; i++)
		{
			if (x[i] != a*x[i - 1] + b)
			{
				printf("B\n");
				return 0;

			}
		}
		printf("%d\n", a*x[n - 1] + b);
	}
}
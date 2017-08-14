#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		int min = 100, sum = 0;
		for (int i = 0; i < 7; i++)
		{
			int a;
			scanf("%d", &a);

			if (!(a & 1))
			{
				sum += a;
				if (min > a)
					min = a;
			}
		}
		printf("%d %d\n", sum, min);
	}

	return 0;
}
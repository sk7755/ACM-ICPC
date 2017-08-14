#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;

		scanf("%d", &n);

		int max = 0; int min = 99;
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);

			if (temp > max)
				max = temp;
			if (temp < min)
				min = temp;
		}

		printf("%d\n", (max - min) * 2);
	}

	return 0;
}
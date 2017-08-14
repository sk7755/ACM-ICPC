#include <cstdio>

int main()
{
	int x[3], y[3];

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);

	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (x[i] == x[j])
				count++;
		}

		if ((count % 2))
		{
			printf("%d ", x[i]);
			break;
		}

	}

	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (y[i] == y[j])
				count++;
		}

		if ((count % 2))
		{
			printf("%d\n", y[i]);
			break;
		}
	}

	return 0;
}
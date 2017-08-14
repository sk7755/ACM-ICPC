#include <cstdio>

int main()
{
	int n;
	int paper[100][100] = { 0, };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
				paper[j][k] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (paper[i][j])
				sum++;
		}
	}

	printf("%d\n", sum);

	return 0;
}
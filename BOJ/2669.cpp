#include <cstdio>

int main()
{
	int coordinate[100][100] = { 0, };
	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				if (!coordinate[j][k])
				{
					coordinate[j][k] = 1;
					ans++;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
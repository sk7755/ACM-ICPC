#include <cstdio>

int main()
{
	int paper[101][101] = { 0, };
	int remain[101] = { 0, };
	int n;

	scanf("%d", &n);

	for (int k = 1; k <= n; k++)
	{
		int x, y, w, h;
		scanf("%d %d %d %d", &x, &y, &w, &h);

		for (int i = y; i < y + h; i++)
		{
			for (int j = x; j < x + w; j++)
			{
				remain[k]++;
				remain[paper[i][j]]--;
				paper[i][j] = k;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", remain[i]);

	return 0;
}
#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	char name[100][20];

	int max=0, max_idx;
	int min= 100000000, min_idx;
	for (int i = 0; i < n; i++)
	{
		int d, m, y;
		scanf("%s %d %d %d", name[i], &d, &m, &y);
		int w = y * 10000 + m * 100 + d;

		if (w> max)
			max = w, max_idx = i;
		if (w < min)
			min = w, min_idx = i;
	}

	printf("%s\n%s\n", name[max_idx], name[min_idx]);

	return 0;
}
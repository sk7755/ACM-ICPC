#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int a[1500][1500];
	int idx[1500];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
		idx[i] = n - 1;
	}

	int max;

	for (int i = 0; i < n; i++)
	{
		max = 0x80000000;
		int max_idx;
		for (int j = 0; j < n; j++)
		{
			if (max < a[idx[j]][j])
			{
				max = a[idx[j]][j];
				max_idx = j;
			}
		}
		idx[max_idx]--;
	}
	printf("%d\n", max);

	return 0;
}
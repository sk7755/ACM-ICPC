#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int max[3] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int l;
		scanf("%d", &l);

		for (int j = 0; j < 3; j++)
		{
			if (max[j] < l)
			{
				for (int k = 2; k > j; k--)
					max[k] = max[k - 1];
				max[j] = l;
				break;
			}
		}
	}

	if (max[0] < max[1] + max[2])
		printf("%d\n", max[0] + max[1] + max[2]);
	else
		printf("-1\n");
}
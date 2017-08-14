#include <cstdio>

int main()
{
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int n;
		scanf("%d", &n);
		int score[101] = { 0, };
		
		for (int j = 0; j < n; j++)
		{
			int temp;
			scanf("%d", &temp);
			score[temp]++;
		}
		printf("Class %d\n", i+1);
		int k;
		for (k = 100; !score[k]; k--)
			;
		printf("Max %d, ", k);

		int pre = k--;
		int l_gap = 0;
		for (; k >= 0; k--)
		{
			if (score[k])
			{
				if (pre - k > l_gap)
					l_gap = pre - k;
				pre = k;
			}
		}

		printf("Min %d, Largest gap %d\n", pre,l_gap);
	}

	return 0;
}
#include <cstdio>

int main()
{
	int ans[100000];

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == -1)
			return 0;

		int sum = 0;
		int k = 0;
		for (int i = 1; i < n; i++)
		{
			if (!(n%i))
			{
				sum += i;
				ans[k++] = i;
			}
		}

		printf("%d ", n);
		if (sum == n)
		{
			printf("= %d", ans[0]);
			for (int i = 1; i < k; i++)
				printf(" + %d", ans[i]);
			printf("\n");
		}
		else
			printf("is NOT perfect.\n");
	}

	return 0;
}
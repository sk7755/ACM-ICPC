#include <cstdio>

void find_pair(int n)
{
	printf("Pairs for %d:", n);
	int flag = 0;
	for (int i = 1; i < n - i; i++)
	{
		int j = n - i;

		if (flag)
			printf(",");

		if (i < j && j<13)
			printf(" %d %d", i, j), flag = 1;

	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;

		scanf("%d", &n);

		find_pair(n);
	}

	return 0;
}
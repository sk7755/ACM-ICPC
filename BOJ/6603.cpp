#include <cstdio>

int n;
int a[13];

void combination(int k, int m);

int main()
{
	while (true)
	{
		scanf("%d", &n);

		if (n == 0)
			return 0;

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		combination(0, 0);
		puts("");
	}
}

int ans[6];

void combination(int k, int m)
{
	if (m == 6)
	{
		for (int i = 0; i < 6; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	if (k == n)
		return;

	for (int i = k; i < n; i++)
	{
		ans[m] = a[i];
		combination(i+1, m + 1);
	}
}
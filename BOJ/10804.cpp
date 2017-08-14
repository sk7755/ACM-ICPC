#include <cstdio>

int main()
{
	int a[21];

	for (int i = 1; i <= 20; i++)
		a[i] = i;

	for (int i = 0; i < 10; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);

		int n = end - start + 1;
		for (int i = 0; i < n / 2; i++)
		{
			int tmp = a[i + start];
			a[i + start] = a[n - i - 1 + start];
			a[n - i - 1 + start] = tmp;
		}
	}

	for (int i = 1; i <= 20; i++)
		printf("%d ", a[i]);
}
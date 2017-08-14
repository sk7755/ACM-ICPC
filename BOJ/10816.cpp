#include <cstdio>
int a[20000001] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp + 10000000]++;
	}
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		printf("%d ", a[tmp + 10000000]);
	}

	return 0;
}
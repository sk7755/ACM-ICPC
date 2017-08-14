#include <cstdio>
#include <algorithm>

using namespace std;

int cmp(int a, int b)
{
	int ord[10] = { 10, 5, 9, 8, 3, 2, 7, 6, 1, 4 };

	if (a < 10 && b >= 10)
	{
		if (a == b / 10)
			return 1;

		return ord[a] < ord[b / 10];

	}
	if (a >= 10 && b < 10)
	{
		if (a / 10 == b)
			return 0;
		
		return ord[a / 10] < ord[b];
	}
	if (a < 10 && b < 10)
		return ord[a] < ord[b];
	else
	{
		if (a / 10 == b / 10)
			return ord[a % 10] < ord[b % 10];
		return ord[a / 10] < ord[b / 10];
	}
}

int main()
{
	int m, n;
	int a[100];
	scanf("%d %d", &n, &m);
	if (n > m)
	{
		int tmp = n;
		n = m;
		m = tmp;
	}
	for (int i = 0; i < m - n + 1; i++)
		a[i] = n + i;

	sort(a, a + m - n + 1, cmp);

	for (int i = 0; i < m - n + 1; i+=10)
	{
		for (int j = 0; j < 10 && i+j<m-n+1; j++)
			printf("%d ",a[i + j]);
		printf("\n");
	}

	return 0;
}
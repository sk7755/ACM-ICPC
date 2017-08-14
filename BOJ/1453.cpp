#include <cstdio>

int main()
{
	int n;
	int a[101] = { 0, };

	scanf("%d", &n);

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);

		if (a[b])
			m++;
		else
			a[b] = 1;
	}

	printf("%d\n", m);
	return 0;
}
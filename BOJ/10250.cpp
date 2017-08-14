#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		int h, w, n;

		scanf("%d %d %d", &h, &w, &n);
		int a = (n-1)%h+1;
		int b = (n - 1) / h + 1;
		printf("%d%02d\n", a,b);
	}

	return 0;
}
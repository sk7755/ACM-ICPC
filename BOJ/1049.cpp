#include <cstdio>

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	int package = 1000, each = 1000;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (package > a)
			package = a;
		if (each > b)
			each = b;
	}
	if (each * 6 < package)
		printf("%d\n", each*n);
	else
	{
		if ((n % 6) * each < package)
			printf("%d\n", (n / 6) * package + (n % 6) * each);
		else
			printf("%d\n", (n / 6 + 1)*package);
	}
	return 0;
}
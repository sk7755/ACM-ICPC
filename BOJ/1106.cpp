#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d %d\n", 2 * b - a, a - b);
	}
}
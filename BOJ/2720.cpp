#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int c;
		scanf("%d", &c);
		printf("%d ", c / 25);
		c %= 25;
		printf("%d ", c / 10);
		c %= 10;
		printf("%d ", c / 5);
		c %= 5;
		printf("%d\n", c);
	}

	return 0;
}
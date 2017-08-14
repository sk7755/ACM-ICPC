#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n << 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i+j) & 1)
				putchar(' ');
			else
				putchar('*');
		}
		putchar('\n');
	}

	return 0;
}
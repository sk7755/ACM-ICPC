#include <cstdio>

int main()
{
	int r, c;
	int a, b;
	scanf("%d %d %d %d", &r, &c, &a, &b);

	for (int i = 0; i < r; i++)
	{
		for (int ii = 0; ii < a; ii++)
		{
			for (int j = 0; j < c; j++)
			{
				char c;
				if ((i + j) % 2)
					c = '.';
				else
					c = 'X';
				for (int jj = 0; jj < b; jj++)
				{
					printf("%c", c);
				}
			}
			printf("\n");
		}
	}

}
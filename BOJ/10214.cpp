#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int y = 0, k = 0;
		for (int i = 0; i < 9; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			y += a; k += b;
		}

		if (y> k)
			printf("Yonsei\n");
		else if (y < k)
			printf("Korea\n");
		else
			printf("Draw\n");
	}

	return 0;
}
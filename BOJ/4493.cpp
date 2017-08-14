#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int a = 0, b = 0;

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			getchar();
			char A, B;
			scanf("%c %c", &A, &B);

			if (A != B)
			{
				if (A == 'R' && B == 'S')
					a++;
				if (A == 'S' && B == 'P')
					a++;
				if (A == 'P' && B == 'R')
					a++;

				if (B == 'R' && A == 'S')
					b++;
				if (B == 'S' && A == 'P')
					b++;
				if (B == 'P' && A == 'R')
					b++;
			}
		}

		if (a > b)
			printf("Player 1\n");
		else if (a < b)
			printf("Player 2\n");
		else
			printf("TIE\n");
	}

	return 0;
}
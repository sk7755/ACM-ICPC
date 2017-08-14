#include <cstdio>

int main()
{
	int score[2][7] = { { 1, 2, 3, 3, 4, 10, 0 }, { 1, 2, 2, 2, 3, 5, 10 } };
	int t;
	scanf("%d", &t);

	for (int k = 1; k <= t;k++)
	{
		int a = 0, b=0;
		for (int i = 0; i < 6; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			a += score[0][i] * tmp;
		}

		for (int i = 0; i < 7; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			b += score[1][i] * tmp;
		}
		printf("Battle %d: ",k);
		if (a>b)
			printf("Good triumphs over Evil\n");
		else if (a < b)
			printf("Evil eradicates all trace of Good\n");
		else
			printf("No victor on this battle field\n");
	}
}
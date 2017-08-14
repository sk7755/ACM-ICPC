#include <cstdio>

int main()
{
	int r[5] = { 0, };
	int c[5] = { 0, };
	int pd[9] = { 0, };
	int nd[9] = { 0, };

	int* num[26][4] = { 0, };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tmp;
			scanf("%d", &tmp);

			num[tmp][0] = &r[i];
			num[tmp][1] = &c[j];
			num[tmp][2] = &pd[i + j];
			num[tmp][3] = &nd[i - j + 4];
		}
	}

	int bingo = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			
			for (int k = 0; k < 4; k++)
			{
				(*num[tmp][k])++;
				if (*num[tmp][k] == 5)
					bingo++;
			}
			if (bingo >= 3)
			{
				printf("%d\n", i * 5 + j + 1);
				return 0;
			}
			

		}
	}
}
#include <cstdio>
#include <cstring>

int main()
{
	int t;
	scanf("%d", &t);

	char name[100][1001];
	int result[100] = { 0, };

	for (int i = 1; i <= t; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
	
		for (int j = 0; j < n; j++)
		{
			scanf("%s", name[j]);
			result[j] = 0;
		}
		char tmp[1001];
		int score;
		for (int j = 0; j < m; j++)
		{
			scanf("%s %d %*s", tmp, &score);

			for (int k = 0; k < n; k++)
			{
				if (strcmp(tmp, name[k]) == 0)
				{
					result[k] += score;
					break;
				}
			}
		}

		int winner = -1;
		int max = -100;
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (result[j] > max)
			{
				max = result[j];
				winner = j;
				flag = 0;
			}
			else if (result[j] == max)
				flag = 1;
		}

		printf("VOTE %d: ",i);
		if (flag)
			printf("THERE IS A DILEMMA\n");
		else
			printf("THE WINNER IS %s %d\n", name[winner], result[winner]);
	}
}
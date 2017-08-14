#include <cstdio>

int main()
{
	int cnt[101][3] = { 0, };

	int score[200][3] = { 0, };

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &score[i][j]);
			cnt[score[i][j]][j]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		for (int j = 0; j < 3; j++)
		{
			if (cnt[score[i][j]][j] == 1)
				ans += score[i][j];
		}

		printf("%d\n", ans);
	}

	return 0;
}
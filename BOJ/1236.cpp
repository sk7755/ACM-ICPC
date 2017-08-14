#include <cstdio>

int main()
{
	char map[51][51];
	int row[50] = { 0, };
	int col[50] = { 0, };

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'X')
				row[i] = col[j] = 1;
		}
	}
	int row_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!row[i])
			row_cnt++;
	}

	int col_cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (!col[i])
			col_cnt++;
	}

	printf("%d\n", row_cnt > col_cnt ? row_cnt : col_cnt);
}
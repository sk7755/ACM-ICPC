#include <cstdio>

inline int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	char str[50][51];

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int limit = min(i, j);
			for (int k = limit; k>=0; k--)
			{
				if (str[i][j] == str[i - k][j] && str[i][j] == str[i][j - k] && str[i][j] == str[i - k][j - k])
				{
					if (max < (k + 1)*(k + 1))
						max = (k + 1)*(k + 1);
					break;
				}
			}
		}
	}

	printf("%d\n", max);
}
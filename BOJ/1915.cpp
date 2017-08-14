#include <cstdio>

inline int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

inline int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}
inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n, m;
	char str[1001];
	int dp[2][1001] = { 0, };
	scanf("%d %d", &n, &m);
	int up = 0, down = 1;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		for (int j = 0; j < m; j++)
		{
			if (str[j] == '0')
				dp[down][j + 1] = 0;
			else
			{
				dp[down][j + 1] = min(min(dp[down][j], dp[up][j]), dp[up][j + 1]) + 1;
				ans = max(ans, dp[down][j + 1]);
			}
		}

		swap(up, down);
	}

	printf("%d\n", ans*ans);

	return 0;
}
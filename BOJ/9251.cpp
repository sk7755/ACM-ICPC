#include <cstdio>
#include <cstring>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int dp[1001][1001] = { 0, };

	char str1[1001];
	scanf("%s", str1);
	int len1 = strlen(str1);

	char str2[1001];
	scanf("%s", str2);
	int len2 = strlen(str2);

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	printf("%d\n", dp[len1][len2]);

	return 0;
}
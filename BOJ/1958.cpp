#include <cstdio>
#include <cstring>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	char str1[101];
	char str2[101];
	char str3[101];

	scanf("%s %s %s", str1, str2, str3);

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);

	int dp[101][101][101] = { 0, };

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			for (int k = 0; k < len3; k++)
			{
				if (str1[i] == str2[j] && str2[j] == str3[k])
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				else
					dp[i + 1][j + 1][k + 1] = max(max(dp[i][j + 1][k + 1], dp[i + 1][j][k + 1]), dp[i + 1][j + 1][k]);
			}
		}
	}

	printf("%d\n", dp[len1][len2][len3]);

	return 0;
}
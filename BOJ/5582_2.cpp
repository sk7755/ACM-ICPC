#include <cstdio>
#include <cstring>


int main()
{
	char str1[4001];
	char str2[4001];
	int dp[4001][4001] = { 0, };

	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int ans = 0;
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			if (ans < dp[i + 1][j + 1])
				ans = dp[i + 1][j + 1];
		}
	}

	printf("%d\n", ans);

	return 0;
}
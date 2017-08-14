#include <cstdio>
#include <cstring>

int main()
{
	char str1[1001];
	char str2[1001];
	int dp[1001][1001] = { 0, };
	int p[1001][1001] = { 0, };
	scanf("%s", str1);
	scanf("%s", str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				p[i + 1][j + 1] = 0;
			}
			else
			{
				if (dp[i][j + 1] < dp[i + 1][j])
					dp[i + 1][j + 1] = dp[i + 1][j], p[i + 1][j + 1] = 1;
				else
					dp[i + 1][j + 1] = dp[i][j + 1], p[i + 1][j + 1] = -1;
			}
		}
	}

	printf("%d\n", dp[len1][len2]);

	int i = len1, j = len2;
	char stack[1000];
	int top = -1;
	while (i > 0 && j > 0)
	{
		if (p[i][j] == 1)
			j--;
		else if (p[i][j] == -1)
			i--;
		else
		{
			stack[++top] = str1[i - 1];
				i--, j--;
		}
	}

	while (top >= 0)
		printf("%c", stack[top--]);
	printf("\n");
	return 0;
}
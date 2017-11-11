#include <cstdio>
#include <cstring>

int main()
{
	char str[2502];
	
	scanf("%s", str+1);
	int len = strlen(str+1);

	int dp[2501] = { 0, };
	int palin[2501] = { 0, };

	for (int i = 1; i <= len; i++)
	{
		dp[i] = 2500;
		for (int j = 1; j <= i ;j++)
		{
			if (str[j] == str[i] && (i - j <= 1 || palin[j + 1]))
			{
				palin[j] = 1;
				if (dp[i] > dp[j - 1] + 1)
					dp[i] = dp[j - 1] + 1;
			}
			else
				palin[j] = 0;
		}
	}
	printf("%d\n", dp[len]);

	return 0;
}
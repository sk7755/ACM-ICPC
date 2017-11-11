#include <cstdio>
#include <cstring>

int main()
{
	char str[2501];
	
	scanf("%s", str);
	int len = strlen(str);

	int palin[2500][2500] = { 0, };

	for (int l = 0; l < len; l++)
	{
		for (int i = 0; i < len - l; i++)
		{
			int j = i + l;
			
			if (str[i] == str[j] && (i+1 > j-1 || palin[i+1][j-1] == 1))
			{
				palin[i][j] = 1;
			}
		}
	}

	int dp[2500] = { 0, };

	for (int i = 0; i < len; i++)
	{
		if (palin[0][i] == 1)
			dp[i] = 1;
		else
		{
			dp[i] = 2500;
			for (int j = i; j >0;j--)
			{
				if (palin[j][i] && dp[i] > dp[j-1] + 1)
					dp[i] = 1 + dp[j - 1];
			}
		}
	}
	printf("%d\n", dp[len - 1]);

	return 0;
}
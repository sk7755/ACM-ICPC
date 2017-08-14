#include <cstdio>
#include <cstring>

enum{m = 1000000};

int main()
{

	while (true)
	{
		char str[5001];
		int dp[5001] = { 1, 1, 0 };
		scanf("%s", str);
		int len = strlen(str);

		for (int i = 1; i < len; i++)
		{
			int temp = (str[i - 1] - '0') * 10 + str[i] - '0';

			if (10 <= temp && temp <= 26)
				dp[i + 1] = dp[i - 1];
			if (str[i] != '0')
				dp[i + 1] = (dp[i + 1] + dp[i]) % m;
		}

		if (str[0] == '0')
		{
			printf("0\n");
			return 0;
		}

		printf("%d\n", dp[len]);
	}
	return 0;
}
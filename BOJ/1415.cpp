#include <cstdio>
#include <algorithm>

void cal(long long dp[][500001], int up, int down, int input);

int main()
{
	int a[500001] = { 0, };

	for (int i = 2; i <= 1000; i++)
	{
		if (!a[i])
		{
			for (int j = i*i; j <= 500000; j += i)
				a[j] = 1;
		}
	}
	int input[51] = { 0, };

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	std::sort(input, input + n );

	long long dp[2][500001] = { 0, };
	int up = 0, down = 1;
	dp[up][0] = 1;
	int count;
	for (int i = 0; i < n;)
	{
		count = 0;
		for (int j = 0; j <= 500000; j++)
			dp[down][j] = dp[up][j];
		
		do
		{
			count++;
			cal(dp, up, down, input[i] * count);
			i++;
		} while (input[i-1] == input[i]);
		
		up ^= 1, down ^= 1;
	}
	long long ans = 0;
	for (int i = 2; i <= 500000; i++)
	{
		if (!a[i])
			ans += dp[up][i];
	}
	
	printf("%lld\n", ans);
}

void cal(long long dp[][500001], int up, int down, int input)
{
	for (int i = input; i <= 500000; i++)
		dp[down][i] += dp[up][i - input];
}

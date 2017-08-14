#include <cstdio>

int main()
{
	int a[1002] = { 0, };
	int dp_inc[1002] = { 0, };
	int dp_dec[1002] = { 0, };

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	//dp increase 계산
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && dp_inc[j] + 1 > dp_inc[i])
			{
				dp_inc[i] = dp_inc[j] + 1;
			}
		}
	}

	//dp decrease 계산
	for (int i = n; i >=1; i--)
	{
		for (int j = n+1; j > i; j--)
		{
			if (a[j] < a[i] && dp_dec[j] + 1 > dp_dec[i])
			{
				dp_dec[i] = dp_dec[j] + 1;
			}
		}
	}

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		if (max < dp_inc[i] + dp_dec[i] - 1)
			max = dp_inc[i] + dp_dec[i] - 1;
	}
	printf("%d\n", max);

	return 0;
}
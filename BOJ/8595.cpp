#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	char str[5000001];
	scanf("%s", str);

	long long ans = 0;
	int hidden = 0;
	for (int i = 0; i <= n; i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			ans += hidden;
			hidden = 0;
		}
		else
		{
			hidden *= 10;
			hidden += str[i] - '0';
		}
	}

	printf("%lld\n", ans);

	return 0;
}
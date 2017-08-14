#include <cstdio>

int main()
{
	int num[4000001] = { 0, };
	int prime[300000];
	int k = 0;
	int n;
	scanf("%d", &n);

	for (long long i = 2; i <= n; i++)
	{
		if (!num[i])
		{
			prime[k++] = i;
			for (long long j = i *i; j <= n; j+=i)
				num[j] = 1;
		}
	}

	int left = 0, right = 0;
	int sum = prime[0];

	int ans = 0;
	while (left <= right && right < k)
	{
		if (sum < n)
			sum += prime[++right];
		else if (sum > n)
			sum -= prime[left++];
		else
		{
			ans++;
			sum += prime[++right] - prime[left++];
		}
	}
	printf("%d\n", ans);


	return 0;
}
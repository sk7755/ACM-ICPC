#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	long long pre = 0;
	for (int i = 1; i <= n; i++)
	{
		long long tmp;
		scanf("%lld", &tmp);

		printf("%lld ", tmp*i - pre);
		pre = tmp*i;
	}
	return 0;
}
#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	long long ans[30] = { 0, };
	ans[0] = 1;
	for (int i = 1; i < 30; i++)
		ans[i] = (ans[i - 1] << 1) + 1;
	while (t--)
	{
		int k;
		scanf("%d", &k);

		printf("%lld\n", ans[k - 1]);

	}
}
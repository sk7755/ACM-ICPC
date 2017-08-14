#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= i;
	for (int i = 1; i <= k; i++)
		ans /= i;
	for (int i = 1; i <= n - k; i++)
		ans /= i;

	printf("%d\n", ans);

	return 0;
}
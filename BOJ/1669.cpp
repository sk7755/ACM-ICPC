#include <cstdio>
#include <cmath>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int n = (int)sqrt(y - x);

	int ans = 2 * n - 1;
	if (y-x != n*n)
		ans++;
	if (y - x > n*n + n)
		ans++;

	if (x == y)
		ans = 0;
	printf("%d\n", ans);
}
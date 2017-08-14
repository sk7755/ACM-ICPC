#include <cstdio>

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}
int main()
{
	int n;
	scanf("%d", &n);

	int pre;
	scanf("%d", &pre);

	int diff[100000];
	int d = 0;
	for (int i = 1; i < n; i++)
	{
		int cur;
		scanf("%d", &cur);
		diff[i] = cur - pre;
		d = gcd(diff[i], d);
		pre = cur;
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans += diff[i] / d - 1;
	}

	printf("%d\n", ans);
}

#include <cstdio>
#include <algorithm>

using namespace std;
int n, k;
int a[11], dp[361][11], q[11], r[361];
void func(int val, int pos)
{
	if (pos == n) return;
	if (dp[val][pos]) return;
	dp[val][pos] = true;
	r[val] = true;
	int next = (val + a[pos] + 360) % 360;
	if (!dp[next][pos]) func(next, pos);
	next = (360 + val - a[pos]) % 360;
	if (!dp[next][pos])func(next, pos);
	func(val, pos + 1);
}

int gcd(int a, int b)
{
	while (b)
	{
		int tmp = b;
		b = a%b;
		a = tmp;
	}

	return a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int d = a[0];

	for (int i = 1; i < n; i++)
		d = gcd(d, a[i]);
	func(0, 0);
	for (int i = 0; i < 4; i++)
	{

		printf("%d %s ",i, i%d == 0 ? "YES" : "NO");
		printf("%s\n", r[i] ? "YES" : "NO");
	}
	return 0;
}
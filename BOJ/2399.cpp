#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[10000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	long long ans = 0;

	for (int k = 1; k <= n; k++)
	{
		ans += (long long)(2 * k - n - 1)*a[k-1];
	}

	printf("%lld\n", 2*ans);
}
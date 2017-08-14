#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[8];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}


	sort(a, a + n);

	int ans = 0;
	if (n % 2)
	{
		int i;
		for (i = 0; i < n / 2 + 1; i++)
			ans -= 2 * a[i];
		ans += a[n / 2] + a[n / 2 - 1];

		for (; i < n; i++)
			ans += 2 * a[i];

		int temp = a[n / 2 ] * 2 - a[n / 2 - 1] - a[n / 2 + 1];
		if (temp > 0)
			ans += temp;

	}
	else
	{
		int i;
		for (i = 0; i < n / 2; i++)
			ans -= 2 * a[i];

		ans += a[n / 2 - 1];
		ans -= a[n/2];

		for (; i < n; i++)
			ans += 2 * a[i];
	}
	printf("%d\n", ans);
}
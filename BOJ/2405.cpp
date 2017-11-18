#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int a[100000];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int ans = 0;

	for (int i = 0; i < n - 2; i++)
	{
		if (ans < a[n - 1] + a[i] - 2 * a[i + 1])
			ans = a[n - 1] + a[i] - 2 * a[i + 1];
		if (ans < a[i + 1] * 2 - a[0] - a[i + 2])
			ans = a[i + 1] * 2 - a[0] - a[i + 2];
	}

	printf("%d\n", ans);

	return 0;
}
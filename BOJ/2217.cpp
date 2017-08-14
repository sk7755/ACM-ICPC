#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[100000];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < a[i] * (n - i))
			ans = a[i] * (n - i);
	}
	printf("%d\n", ans);
}
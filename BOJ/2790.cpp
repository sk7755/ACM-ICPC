#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int a[300000];

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int max = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = n - i + a[i];
		if (tmp > max)
			max = tmp;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] + n >= max)
		{
			ans = n - i;
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}
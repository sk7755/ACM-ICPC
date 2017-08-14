#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long long a[1000001];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	sort(a, a + n);

	long long pre = 0;
	int count = 0;
	int max = 0;
	long long ans;
	a[n] = 0;
	for (int i = 0; i < n+1; i++)
	{
		if (pre != a[i])
		{
			if (max < count)
			{
				max = count;
				ans = pre;
			}
			count = 1;
		}
		else
			count++;
		pre = a[i];
	}

	printf("%lld\n", ans);

	return 0;
}
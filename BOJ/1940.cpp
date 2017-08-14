#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[15000];
	int n,m;
	scanf("%d %d", &n,&m);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int left = 0, right = n - 1;

	int ans = 0;
	while (left < right)
	{
		if (a[left] + a[right] < m)
			left++;
		else if (a[left] + a[right] > m)
			right--;
		else
			ans++, left++, right--;
	}
	printf("%d\n", ans);

	return 0;
}
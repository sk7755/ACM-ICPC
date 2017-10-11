#include <cstdio>
#include <algorithm>

int main()
{
	int a[10000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	std::sort(a, a + n);

	int p = a[0] * a[1];	//--
	int q = a[n - 1] * a[n - 2];	//++

	int ans;
	if (p < q)
		ans = q;
	else
		ans = p;

	if (ans < p*a[n - 1])	//--+
		ans = p*a[n - 1];
	if (ans < q * a[n - 3])	//+++
		ans = q*a[n - 3];

	printf("%d\n", ans);

	return 0;
}
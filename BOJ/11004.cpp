#include <cstdio>
#include <algorithm>

int main()
{
	int a[5000000];
	int n,k;

	scanf("%d %d", &n,&k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	std::sort(a, a + n);

	printf("%d\n", a[k-1]);

	return 0;
}
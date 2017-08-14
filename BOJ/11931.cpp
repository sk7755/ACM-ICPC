#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[1000000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	for (int i = n - 1; i >= 0; i--)
		printf("%d\n", a[i]);

	return 0;
}
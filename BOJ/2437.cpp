#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[1000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int r = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > r + 1)
		{
			printf("%d\n", r + 1);
			return 0;
		}
		
		r += a[i];
	}
	printf("%d\n", r + 1);
	return 0;
}
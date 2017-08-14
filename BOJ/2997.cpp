#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[3];

	for (int i = 0; i < 3; i++)
		scanf("%d", &a[i]);

	sort(a, a + 3);

	int d1 = a[1] - a[0];
	int d2 = a[2] - a[1];

	if (d1 == d2)
		printf("%d\n", a[2] + d1);
	else if (d1 == d2 * 2)
		printf("%d\n", (a[0] + a[1]) / 2);
	else
		printf("%d\n", (a[1] + a[2]) / 2);

	return 0;
}
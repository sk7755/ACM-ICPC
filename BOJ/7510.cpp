#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[3];
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[j]);
		sort(a, a + 3);

		printf("Scenario #%d:\n", i);
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
			printf("yes\n");
		else
			printf("no\n");
		printf("\n");
	}

	return 0;
}
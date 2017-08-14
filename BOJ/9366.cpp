#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		int a[3];
		scanf("%d %d %d", &a[0], &a[1], &a[2]);

		sort(a, a + 3);

		printf("Case #%d: ", i);

		if (a[0] + a[1] <= a[2])
			printf("invalid!\n");
		else
		{
			if (a[0] == a[2])
				printf("equilateral\n");
			else if (a[0] == a[1] || a[1] == a[2])
				printf("isosceles\n");
			else
				printf("scalene\n");
		}
	}

	return 0;
}
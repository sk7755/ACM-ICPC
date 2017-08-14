#include <cstdio>
#include <algorithm>

using namespace std;

int n, c;
int a[200000];

int lower_bound(int left, int right);
int check(int dist);

int main()
{
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	printf("%d\n", lower_bound(1,a[n-1]-a[0]));

	return 0;
}

int lower_bound(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (check(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}

int check(int dist)
{
	int pre = -1000000000;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] - pre >= dist)
		{
			cnt++;
			if (cnt == c)
				return 1;
			pre = a[i];
		}
	}

	return 0;
}
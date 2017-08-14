#include <cstdio>
#include <algorithm>

using namespace std;

int lowerbound(int a[], int n, int h);

int main()
{
	int n, h;

	scanf("%d %d", &n, &h);

	int a[100000];
	int b[100000];

	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (i % 2)
			b[i / 2] = tmp;
		else
			a[i / 2] = tmp;
	}

	sort(a, a + n / 2);
	sort(b, b + n / 2);

	int min = 200000;
	int cnt = 0;
	for (int i = 1; i <= h; i++)
	{
		int tmp = lowerbound(a, n / 2, i) + lowerbound(b, n / 2, h - i + 1);

		if (min > tmp)
			min = tmp, cnt = 1;
		else if (min == tmp)
			cnt++;
	}
	printf("%d %d\n", min, cnt);

	return 0;
}

int lowerbound(int a[], int n, int h)
{
	int left = 0, right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (a[mid] >= h)
			right = mid - 1;
		else if (a[mid] < h)
			left = mid + 1;
	}

	return n - right - 1;
}
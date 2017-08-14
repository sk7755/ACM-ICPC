#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void qsort(int a[], int left, int right);
int partition(int a[], int left, int right);
int binary_search(int a[], int left, int right, int key);

int main()
{
	int n, m;
	int a[200000];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a+n);
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		cnt += binary_search(a, 0, n - 1, tmp);
	}

	printf("%d\n", n + m - cnt * 2);

	return 0;
}

void qsort(int a[], int left, int right)
{
	if (left >= right)
		return;

	int idx = partition(a, left, right);
	qsort(a, left, idx - 1);
	qsort(a, idx + 1, right);
}

int partition(int a[], int left, int right)
{
	int pivot = rand()% (right - left + 1) + left;
	int tmp = a[right];
	a[right] = a[pivot];
	a[pivot] = tmp;

	int key = a[right];

	int j = left;
	for (int i = left; i < right; i++)
	{
		if (key > a[i])
		{
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			j++;
		}
	}
	tmp = a[j];
	a[j] = a[right];
	a[right] = tmp;

	return j;
}

int binary_search(int a[], int left, int right, int key)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (a[mid] < key)
			left = mid + 1;
		else if (a[mid] > key)
			right = mid - 1;
		else
			return 1;
	}

	return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;
int upper(int a[], int n, int val);
int lower(int a[], int n, int val);

inline int abs(int x)
{
	return x < 0 ? -x : x;
}

int main()
{
	int n, m;
	long long ans = 0;
	scanf("%d %d", &n, &m);

	int x[100000], y[100000];

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		ans += abs(x[i]) + abs(y[i]);
	}
	sort(x, x + n);
	sort(y, y + n);
	int a = 0, b = 0;

	char cmd[300001];
	scanf("%s", cmd);

	for (int i = 0; i < m; i++)
	{
		int m;
		if (cmd[i] == 'S')
		{
			m = upper(y, n, b);
			b++;
			ans += 2 * m - n;
		}
		else if (cmd[i] == 'J')
		{

			m = lower(y, n, b);
			b--;
			ans += n - 2 * m;
		}
		else if (cmd[i] == 'I')
		{
			m = upper(x, n, a);
			a++;
			ans += 2 * m - n;
		}
		else
		{
			m = lower(x, n, a);
			a--;
			ans += n - 2 * m;
		}
		printf("%lld\n", ans);
	}

}

int upper(int a[],int n, int val)
{
	int left = 0, right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] <= val)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}

int lower(int a[], int n, int val)
{
	int left = 0, right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] >= val)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}
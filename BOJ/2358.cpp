#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int x[100000];
	int y[100000];

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	sort(x, x + n);
	sort(y, y + n);

	int pre_x = x[0];
	int cnt_x = 1;
	int pre_y = y[0];
	int cnt_y = 1;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (pre_x != x[i])
		{
			if (cnt_x >= 2)
				ans++;
			cnt_x = 1;
		}
		else
			cnt_x++;
		if (pre_y != y[i])
		{
			if (cnt_y >= 2)
				ans++;
			cnt_y = 1;
		}
		else
			cnt_y++;

		pre_x = x[i];
		pre_y = y[i];
	}

	if (cnt_x >= 2)
		ans++;
	if (cnt_y >= 2)
		ans++;
	printf("%d\n", ans);

	return 0;
}
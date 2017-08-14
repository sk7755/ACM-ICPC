#include <cstdio>

int main()
{
	int a[7];

	int ans = 0;
	for (int i = 1; i <= 6; i++)
		scanf("%d", &a[i]);

	ans += a[6];
	ans += a[5];
	if (a[5] * 11 >= a[1])
		a[1] = 0;
	else
		a[1] -= a[5] * 11;
	ans += a[4];
	if (a[4] * 5 >= a[2])
	{
		a[2] = 0;
		if ((a[4] * 5 - a[2]) * 4 >= a[1])
			a[1] = 0;
		else
			a[1] -= (a[4] * 5 - a[2]) * 4;
	}
	else
		a[2] -= a[4] * 5;
	ans += a[3] / 4;
	int tmp = a[3] % 4;

	if (tmp == 0)
	{
		;
	}

}
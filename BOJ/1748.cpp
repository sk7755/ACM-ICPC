#include <cstdio>

int main()
{
	int a[10] = { 0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999 };

	int n;

	scanf("%d", &n);

	int digit;
	for (int i = 1; i <= 9; i++)
	{
		if (a[i] > n)
		{
			digit = i;
			break;
		}
	}
	int ans = (n - a[digit-1]) * digit;

	for (digit = digit-1; digit > 0; digit--)
	{
		ans += digit * (a[digit] - a[digit - 1]);
	}

	printf("%d\n", ans);
}
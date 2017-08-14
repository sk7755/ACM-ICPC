#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int start = 1;
	int inc = 1;
	int del = 0;

	while (n != 1)
	{
		start += inc*(del ^ 1);
		if (n % 2)
		{
			n = n / 2 + del;
			del ^= 1;
		}
		else
		{
			n /= 2;
		}
		inc *= 2;
	}

	printf("%d\n", start);
}
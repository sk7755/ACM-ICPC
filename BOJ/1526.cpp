#include <cstdio>
#include <cstring>

int check(int n)
{
	while (n)
	{
		int a = n % 10;
		if (a != 4 && a != 7)
			return 0;
		n /= 10;
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = n; i >= 4; i--)
	{
		if (check(i))
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
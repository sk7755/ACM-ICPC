#include <cstdio>

int main()
{
	int x;

	scanf("%d", &x);

	int n = 0;
	for (int i = 1; i <= 64; i = i << 1)
	{
		if (x & i)
			n++;
	}
	printf("%d\n", n);

	return 0;
}
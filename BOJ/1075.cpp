#include <cstdio>

int main()
{
	int n,f;

	scanf("%d %d", &n, &f);

	n -= n % 100;

	printf("%02d\n", (f - n%f) %f);

	return 0;
}
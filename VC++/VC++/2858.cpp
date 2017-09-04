#include <cstdio>
#include <cmath>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int x = (a + 4 + (int)sqrt((a - 4)*(a - 4) - 16 * b) )/ 4;
	int y = a / 2 + 2 - x;

	printf("%d %d\n", x, y);

	return 0;
}
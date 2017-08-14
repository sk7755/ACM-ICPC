#include <cstdio>

int main()
{
	int l, a, b, c, d;

	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	int s = a / c ;
	if (a%c)
		s++;
	int t = b / d;
	if (b%d)
		t++;
	if (s < t)
		s = t;

	if (l > s)
		printf("%d\n", l - s);
	else
		printf("0\n");

	return 0;
}
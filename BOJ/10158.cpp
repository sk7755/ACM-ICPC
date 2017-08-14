#include <cstdio>

int main()
{

	int w, h;
	int p, q;
	int t;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	scanf("%d", &t);

	int x = (t + p) % (2 * w);
	int y = (t + q) % (2 * h);

	if (x > w)
		x = 2 * w - x;
	if (y > h)
		y = 2 * h - y;

	printf("%d %d\n", x, y);

	return 0;
}

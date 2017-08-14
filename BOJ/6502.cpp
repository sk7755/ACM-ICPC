#include <cstdio>

int main()
{
	for(int i = 1;;i++)
	{
		int r;
		scanf("%d", &r);

		if (r == 0)
			return 0;
		int w, h;

		scanf("%d %d", &w, &h);
		printf("Pizza %d ", i);
		if (w*w + h*h <= 4 * r*r)
			printf("fits on the table.\n");
		else
			printf("does not fit on the table.\n");
	}
	return 0;
}
#include <cstdio>

int main()
{
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);

	int limit = w*w + h*h;

	for (int i = 0; i < n; i++)
	{
		int l;
		scanf("%d", &l);

		if (l*l <= limit)
			printf("DA\n");
		else
			printf("NE\n");
	}
	return 0;
}
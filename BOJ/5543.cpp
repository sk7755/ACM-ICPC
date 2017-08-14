#include <cstdio>

int main()
{
	int h=2000, b= 2000;

	for (int i = 0; i < 3; i++)
	{
		int p;
		scanf("%d", &p);

		if (p < h)
			h = p;
	}

	for (int i = 0; i < 2; i++)
	{
		int p;
		scanf("%d", &p);
		if (p < b)
			b = p;
	}

	printf("%d\n", h + b- 50);

	return 0;
}
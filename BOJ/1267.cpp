#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int y = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		y += (tmp / 30 + 1) * 10;
		m += (tmp / 60 + 1) * 15;
	}

	if (y < m)
		printf("Y %d\n", y);
	else if (y > m)
		printf("M %d\n", m);
	else
		printf("Y M %d\n", y);
	return 0;
}
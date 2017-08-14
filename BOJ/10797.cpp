#include <cstdio>

int main()
{
	int n,m,s = 0;

	scanf("%d", &n);

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &m);

		if (n == m)
			s++;
	}

	printf("%d\n", s);

	return 0;
}
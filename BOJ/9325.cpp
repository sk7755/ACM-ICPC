#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	int s, n;
	while (t--)
	{
		scanf("%d", &s);
		scanf("%d", &n);
		int price = s;
		int q, p;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &q, &p);
			price += p*q;
		}

		printf("%d\n", price);
	}

	return 0;
}
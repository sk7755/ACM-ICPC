#include <cstdio>

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int a, b;

		scanf("%d %d", &a, &b);
		if (a < b)
			swap(a, b);

		int m = a*b;

		while (b)
		{
			a %= b;
			swap(a, b);
		}

		printf("%d %d\n", m / a, a);

	}
	return 0;
}
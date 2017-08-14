#include <cstdio>

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a, b, c;
	while (true)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		if (a > b)
			swap(a, b);
		if (b > c)
			swap(b, c);
		if (a > b)
			swap(a, b);

		if (c*c == a*a + b*b)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
#include <cstdio>

int main()
{
	int a, b;

	while (true)
	{
		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0)
			break;

		if (!(b%a))
			printf("factor\n");
		else if (!(a%b))
			printf("multiple\n");
		else
			printf("neither\n");
	}

	return 0;
}
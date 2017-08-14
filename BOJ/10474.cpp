#include <cstdio>

int main()
{
	while (true)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (!a && !b)
			return 0;

		printf("%d %d / %d\n",a / b, a%b, b);
	}
}
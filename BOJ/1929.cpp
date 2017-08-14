#include <cstdio>

int main()
{
	char num[1000001] = { 0, };

	num[1] = 1;

	int a, b;

	scanf("%d %d", &a, &b);

	for (int i = 3; i*i <= b; i+=2)
	{
		for (int j = i*i; j <= b; j += i)
			num[j] = 1;
	}

	if (a <= 2)
		printf("2\n");

	if (!(a % 2))
		a++;

	for (int i = a; i <= b; i+=2)
	{
		if (!num[i])
			printf("%d\n", i);
	}

	return 0;
}
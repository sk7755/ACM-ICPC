#include <cstdio>

int main()
{
	int A = 0, B = 0;
	int a[10], b[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < 10; i++)
		scanf("%d", &b[i]);

	int last = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i]>b[i])
			A += 3 , last = 1;
		else if (a[i] < b[i])
			B += 3 , last = 2;
		else
			A++, B++;
	}
	printf("%d %d\n", A, B);
	if (A > B)
		printf("A\n");
	else if (A < B)
		printf("B\n");
	else
	{
		if (last == 1)
			printf("A\n");
		else if (last == 2)
			printf("B\n");
		else
			printf("D\n");
	}
}
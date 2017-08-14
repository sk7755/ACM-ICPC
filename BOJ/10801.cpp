#include <cstdio>

int main()
{
	int A=0, B=0;
	int a[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < 10; i++)
	{
		int temp;
		scanf("%d", &temp);

		if (temp >a[i])
			B++;
		else if (temp < a[i])
			A++;
	}

	if (A < B)
		printf("B\n");
	else if (A>B)
		printf("A\n");
	else
		printf("D\n");

	return 0;
}
#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int A[7], B[7];

	for (int i = 6; i >= 0; i--)
	{
		A[i] = a % 10;
		B[i] = b % 10;
		a /= 10;
		b /= 10;
	}

	for (int i = 6; i >= 0; i--)
		A[i] += B[i];

	int i;
	for (i = 0; i <= 6; i++)
	{
		if (A[i])
			break;
	}
	for (; i <= 6; i++)
		printf("%0d", A[i]);

	return 0;

}
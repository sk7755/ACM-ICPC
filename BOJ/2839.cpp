#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int q5 = n / 5;
	int q3 = 0;
	int r = n % 5;

	if (r == 1)
		q5--, q3 = 2;
	else if (r == 2)
		q5 -= 2, q3 = 4;
	else if (r == 3)
		q3++;
	else if (r == 4)
		q5 --,q3 =3;

	if (q5 < 0)
	{
		printf("-1\n");
		return 0;
	}

	printf("%d\n", q5 + q3);

	return 0;
}
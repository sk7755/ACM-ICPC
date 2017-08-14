#include <cstdio>

inline int cmp(char a[])
{
	int len_a, len_b;
	int i;
	for (i = 0; a[i]; i++)
	{
		if (a[i] == ' ')
		{
			len_a = i;
		}
	}
	len_b = i - 1 - len_a;


	if (len_a > len_b)
		return 1;
	if (len_a < len_b)
		return -1;

	for (int i = 0; i < len_a; i++)
	{
		int j = i + len_a + 1;
		if (a[i] > a[j])
			return 1;
		if (a[i] < a[j])
			return -1;
	}

	return 0;

}

int main()
{
	int n;
	scanf("%d", &n);

	int A = 0, B = 0;
	char a[10];
	getchar();
	while (n--)
	{
		gets(a);

		int result = cmp(a);

		if (result == 1)
			A++;
		else if (result == -1)
			B++;
	}

	printf("%d %d", A, B);

	return 0;
}
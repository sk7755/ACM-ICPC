#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);
	char str[16];

	scanf("%s", str);

	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'A')
			a++;
		else
			b++;
	}
	if (a>b)
		printf("A\n");
	else if (a < b)
		printf("B\n");
	else
		printf("Tie\n");

	return 0;
}
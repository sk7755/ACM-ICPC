#include <cstdio>

int main()
{
	char str[10];
	int a[3];

	for (int i = 0; i < 3; i++)
	{
		scanf("%s", str);

		if (str[0] == 'b')
		{
			if (str[1] == 'l')
			{
				if (str[2] == 'a')
					a[i] = 0;
				else
					a[i] = 6;
			}
			else
				a[i] = 1;
		}
		else if (str[0] == 'r')
			a[i] = 2;
		else if (str[0] == 'o')
			a[i] = 3;
		else if (str[0] == 'y')
			a[i] = 4;
		else if (str[0] == 'g')
		{
			if (str[3] == 'e')
				a[i] = 5;
			else
				a[i] = 8;
		}
		else if (str[0] == 'v')
		{
			a[i] = 7;
		}
		else if (str[0] == 'w')
			a[i] = 9;
	}

	int sum = 10 * a[0] + a[1];

	printf("%d", sum);
	if (sum)
	{
		for (int i = 0; i < a[2]; i++)
			printf("0");
	}
	printf("\n");

	return 0;
}
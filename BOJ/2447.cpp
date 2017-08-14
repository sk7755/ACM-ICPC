#include <cstdio>

char ans[2187][2188];
void print_start(int n);

int main()
{
	int n;
	scanf("%d", &n);

	print_start(n);

	for (int i = 0; i < n; i++)
		printf("%s\n", ans[i]);
}

void print_start(int n)
{
	if (n == 1)
	{
		ans[0][0] = '*';
		return;
	}

	print_start(n / 3);

	for (int s = 0; s < n; s += n / 3)
	{
		for (int t = 0; t < n; t += n / 3)
		{
			for (int i = 0; i < n / 3; i++)
			{
				for (int j = 0; j < n / 3; j++)
				{
					ans[i + s][j + t] = ans[i][j];
				}
			}
		}
	}
	for (int i = 0; i < n / 3; i++)
	{
		for (int j = 0; j < n / 3; j++)
		{
			ans[i + n/3][j + n/3] = ' ';
		}
	}

	for (int i = 0; i < n; i++)
		ans[i][n] = '\0';
	return;
}
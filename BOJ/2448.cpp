#include <cstdio>
#include <cstring>

char str[3072][6200] = { 0, };

void star(int k, int n)
{
	if (n == k)
		return;

	for (int i = 0; i < k; i++)
	{
		str[i + k][2 * k - 1] = ' ';
		for (int j = 0; j < 2 * k - 1; j++)
			str[i+k][j] = str[i+k][j+2*k] = str[i][j];
	}
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 4 * k - 1; j++)
			str[i][j] = ' ';
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 2 * k - 1; j++)
			str[i][j + k] = str[i + k][j];
	}
	star(2 * k, n);
}

int main()
{
	strcpy(str[0], "  *  ");
	strcpy(str[1], " * * ");
	strcpy(str[2], "*****");

	int n;
	scanf("%d", &n);
	star(3, n);

	for (int i = 0; i < n; i++)
		printf("%s\n", str[i]);
	return 0;
}
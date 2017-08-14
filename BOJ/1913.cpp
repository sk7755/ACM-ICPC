#include <cstdio>

int matrix[999][999];
int n;

void solver(int n);

int main()
{
	int m;
	scanf("%d %d", &n,&m);

	solver(0);

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	if (m == 1)
	{
		printf("%d %d\n", n / 2 + 1, n / 2 + 1);
		return 0;
	}

	int cur = 0;
	while ((n - 2 * cur - 2) * (n - 2 * cur - 2) >= m)
		cur++;

	int left = cur, right = n - cur - 1;
	int number = (right - cur + 1) * (right - cur + 1);
	int diff = number - m;
	int length = right - left;
	int x, y;
	if (diff < length)
		x = left + diff, y = left;
	else if (diff < 2 * length)
		x = right, y = left + diff - length;
	else if (diff < 3 * length)
		x = right - (diff - 2 * length), y = right;
	else
		x = left, y = right - (diff - 3 * length);

	printf("%d %d\n", x+1, y+1);

	return 0;
}

void solver(int cur)
{
	int left = cur, right = n - cur - 1;
	int number = (right - cur + 1) * (right - cur + 1);

	if (cur == n / 2)
	{
		matrix[left][right] = number;
		return ;
	}

	for (int i = left; i < right; i++)
		matrix[i][left] = number--;
	for (int i = left; i < right; i++)
		matrix[right][i] = number--;
	for (int i = right; i>left; i--)
		matrix[i][right] = number--;
	for (int i = right; i > left; i--)
		matrix[left][i] = number--;

	solver(cur + 1);
	return;
}


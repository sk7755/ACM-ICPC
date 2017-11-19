#include <cstdio>

int binary_search(int a[], int left, int right, int val);

int main()
{
	int n;
	scanf("%d", &n);

	int m[700001] = { 0,1,3};

	if (n == 1)
	{
		printf("1\n");
		return 0;
	}

	int x = 1;
	for (int i = 2; i <= 700000; i++)
	{
		if (m[x] < i)
			x++;
		
		m[i] = m[i - 1] + x;
		if (n <= m[i])
		{
			printf("%d\n", i);
			return 0;
		}
	}
}
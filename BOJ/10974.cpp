#include <cstdio>

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void permutation(int a[], int m, int n);

char buff[685441];
int k = 0;

int main()
{
	int n;
	int a[8];
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	permutation(a, 0, n);
	buff[k++] = '\0';

	printf("%s", buff);

	return 0;
}

void permutation(int a[],int m, int n)
{
	if (m == n - 1)
	{
		for (int i = 0; i < n; i++)
		{
			buff[k++] = a[i] + '0';
			buff[k++] = ' ';
		}
		buff[k++] = '\n';
		return;
	}
	for (int i = m; i < n; i++)
	{
		swap(a[m], a[i]);
		permutation(a,m+1, n);
	}

	int temp = a[m];
	for (int i = m; i < n - 1; i++)
		a[i] = a[i + 1];
	a[n - 1] = temp;

	return;
}
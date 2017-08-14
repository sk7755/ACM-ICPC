#include <cstdio>

inline void myitoa(char* buff, int n, int& k)
{
	if (n == 0)
	{
		buff[k++] = '0';
		buff[k++] = ' ';
		return;
	}

	if (n < 0)
	{
		buff[k++] = '-';
		n = -n;
	}

	int t = 0;
	char str[10];

	while (n)
	{
		str[t++] = n % 10 + '0';
		n /= 10;
	}

	for (int i = t-1; i >= 0; i--)
	{
		buff[k++] = str[i];
	}

	buff[k++] = ' ';
}

int main()
{
	int a[1000000], b[1000000];
	char buff[30000000];
	int k = 0;

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			myitoa(buff, a[i++], k);
		}
		else if (a[i] > b[j])
		{
			myitoa(buff, b[j++], k);
		}
		else
		{
			myitoa(buff, a[i++], k);
			myitoa(buff, b[j++], k);
		}
	}

	while (i<n)
		myitoa(buff, a[i++], k);
	while (j<m)
		myitoa(buff, b[j++], k);
	buff[k++] = '\0';
	printf("%s\n",buff);
	return 0;
}
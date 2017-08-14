#include <cstdio>
#include <cstring>

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	char str[5];
	char ans[10000];

	int k = 0;
	int temp = n;
	while (temp)
	{
		str[k++] = temp % 10 +'0';
		temp /= 10;
	}

	int t = 0;
	for (int i = 0; i < n && t < m; i++)
	{
		for (int j = k - 1; j >= 0 && t < m; j--)
		{
			ans[t++] = str[j];
		}
	}

	ans[t] = '\0';

	printf("%s\n", ans);

	return 0;
}
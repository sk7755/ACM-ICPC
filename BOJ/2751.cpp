#include <cstdio>

int main()
{
	int n;
	int a[2000001] = { 0, };
	char buffer[8000001];

	scanf("%d", &n);

	int m;
	for (int i = 0; i < n; i++)
		scanf("%d", &m), a[m + 1000000]++;


	int k = 0;
	int t = 8000000;
	buffer[t--] = '\0';
	char str[11];

	for (int i = 2000000; k< n; i--)
	{
		if (a[i])
		{
			int b = i - 1000000;

			int w = 0;
			str[w++] = '\n';

			if (b == 0)
			{
				str[w++] = '0';
			}
			else if (b> 0)
			{
				while (b)
				{
					str[w++] = b % 10 + '0';
					b /= 10;
				}
			}
			else
			{
				b = -b;
				while (b)
				{
					str[w++] = b % 10 + '0';
					b /= 10;
				}
				str[w++] = '-';
			}

			for (int j = 0; j < a[i]; j++)
			{
				for (int l = 0; l < w;l++)
					buffer[t--] = str[l];
			}

			k += a[i];
		}
	}

	printf("%s", buffer + t+1);

	return 0;
}
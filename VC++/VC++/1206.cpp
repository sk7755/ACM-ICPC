#include <stdio.h>

int main()
{
	int k = 0;
	double f = 1;
	f *= 1000;
	printf("%lf\n", f);
	printf("%lld\n", (long long)f);
	//printf("%d\n", (int)(1.001 * (double)1000));
	//for (double f = 1; f <= 2; f += 0.001, k++)
	//		printf("%d %d\n",k%1000, (int)(f * 1000));

	return 0;
	int n;
	scanf("%d", &n);
	int a[100];
	double m;
	if (!n)
	{
		printf("1");
		return 0;
	}
	char str[7];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &str);
		if (str[1] == '.')
		{
			a[i] = (str[2] - '0') * 100 + (str[3] - '0') * 10 + str[4] - '0';
		}
		else
		{
			a[i] = (str[3] - '0') * 100 + (str[4] - '0') * 10 + str[5] - '0';
		}
	}
	int d = 1;
	for (int i = 1;; i++)
	{
		int S = 0;
		for (int p = 0; p<n; p++)
		{
			k = a[p];
			int v;
			for (v = 0; v<d; v++)
			{
				//d 는 사람 v는 d로 나눠졌을때 나머지 
				int t = ((v * 1000) / d) % 1000;
				if (k == t)
				{
					S++;
					break;
				}
			}
			if (v == d)
				break;
		}
		if (S == n)
		{
			printf("%d\n", d);
			return 0;
		}
		d++;
	}
}
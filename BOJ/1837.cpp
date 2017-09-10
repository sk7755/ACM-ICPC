#include <cstdio>
#include <cstring>

int main()
{
	bool num[1000001] = { 0, };

	for (int i = 2; i <= 1000; i++)
	{
		if (!num[i])
		{
			for (int j = i*i; j <= 1000000; j += i)
				num[j] = 1;
		}
	}
	char p[102];
	int k;
	scanf("%s %d", p, &k);
	int len = strlen(p);

	for (int i = 2; i <= k; i++)
	{
		if (!num[i])
		{
			int ret = 0;
			for (int t = 0; t < len; t++)
			{
				ret *= 10;
				ret %= i;
				ret += p[t] - '0';
			}
			if (!(ret % i))
			{
				printf("BAD %d\n", i);
				return 0;
			}
		}
	}

	printf("GOOD\n");
	return 0;
}

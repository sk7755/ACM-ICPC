//피보나치 수열의 일반항 combinatorics
//주기성

#include <cstdio>

int main()
{
	int c[1000] = { 1,5, };

	for (int i = 2; i < 103; i++)
	{
		c[i] = (c[i - 1] * 6 - c[i - 2] * 4 + 1) % 1000;
		if (c[i] < 0)
			c[i] += 1000;
	}

	int t;
	scanf("%d", &t);

	for(int i = 1;i<=t;i++)
	{
		int n;
		scanf("%d", &n);
		
		if (n >= 103)
		{
			n %= 100;
			if (n < 3)
				n += 100;
		}
			
		
		printf("Case #%d: %03d\n",i,c[n]);
	}
}
#include <cstdio>
#include <cmath>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n;
		scanf("%d", &n);

		
		for (int i = 2; i*i <= n; i++)
		{
			int count = 0;
			if (!(n % i))
			{
				while (!(n%i))
				{
					count++;
					n /= i;
				}
				printf("%d %d\n", i,count);
			}
		}
		if (n > 1)
			printf("%d 1\n", n);
	}
}
#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int ans = 0;
	for (int k = 1;; k++)
	{
		if (n / k - (k - 1) / 2 <= 0)
			break;

		if (k % 2)
		{
			if (!(n%k))
				ans++;
		}
		else
		{
			int m = k / 2;
			if ( !(n%m) && (n / m) % 2)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0; 
}
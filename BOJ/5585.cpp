#include <cstdio>

int main()
{
	int n;
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	scanf("%d", &n);

	n = 1000 - n;
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		ans += n/coin[i];
		n %= coin[i];
	}

	printf("%d\n", ans);

}
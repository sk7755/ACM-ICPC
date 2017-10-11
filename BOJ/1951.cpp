#include <cstdio>

enum{m = 1234567};

int pow_mod(int n);

int main()
{
	int n;
	scanf("%d", &n);

	int tmp = n;
	int digit = 0;
	while (tmp)
	{
		digit++;
		tmp /= 10;
	}
	int ans = 0;
	for (int i = 1; i < digit; i++)
		ans = (ans + 9 * i * pow_mod(i - 1)) % m;
	ans = (ans + digit * (n%m - pow_mod(digit - 1) + 1))%m;
	
	printf("%d\n", ans);

	return 0;
}

int pow_mod(int n)
{
	int ret = 1;
	for (int i = 0; i < n; i++)
		ret = (ret * 10) % m;

	return ret;
}
#include <cstdio>

int get_cipher(int a);
int is_prime(int a);
int pow_10(int n);
int make_palin(int n, int i);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int cipher_a = get_cipher(a);
	int cipher_b = get_cipher(b);

	for (int i = cipher_a; i <= cipher_b; i++)
	{
		int tmp = (i + 1) / 2 - 1;
		int start = pow_10(tmp);
		int finish = 0;

		while (tmp>=0)
		{
			finish += 9 * pow_10(tmp);
			tmp--;
		}

		for (int j = start; j <= finish; j++)
		{
			int palin = make_palin(j, i);
			if (a<= palin && palin <= b && is_prime(palin))
				printf("%d\n", palin);
		}
	}

	printf("-1\n");
}

int get_cipher(int a)
{
	int ret = 0;
	while (a)
		a /= 10, ret++;

	return ret;
}

int is_prime(int a)
{
	if (a > 2 && !(a % 2))
		return 0;
	for (int i = 3; i*i <= a; i+=2)
	{
		if (!(a%i))
			return 0;
	}

	return 1;
}

int pow_10(int n)
{
	int ret = 1;
	for (int i = 0; i < n; i++)
		ret *= 10;

	return ret;
}

int make_palin(int n, int i)
{
	int ret = n;

	if (i % 2)
		n /= 10;

	while (n)
	{
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}

	return ret;
}
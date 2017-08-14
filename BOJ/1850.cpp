#include <cstdio>

inline void swap(long long& a, long long& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	long long a, b;

	scanf("%lld %lld", &a, &b);

	if (a < b)
		swap(a, b);

	while (b)
	{
		a %= b;
		swap(a, b);
	}

	char str[10000010];

	for (long long i = 0; i < a; i++)
		str[i] = '1';
	str[a] = '\0';

	printf("%s\n", str);

	return 0;
}
#include <cstdio>

int main()
{
	int n;
	long long a[2][21] = { 0 };
	scanf("%d", &n);

	int up = 0, down = 1;

	int tmp;
	scanf("%d", &tmp);
	a[up][tmp] = 1;

	for (int i = 1; i < n - 1; i++)
	{
		scanf("%d", &tmp);

		for (int i = 0; i <= 20; i++)
			a[down][i] = 0;

		for (int i = 0; i + tmp <= 20; i++)
			a[down][i + tmp] += a[up][i];

		for (int i = tmp; i <= 20; i++)
			a[down][i - tmp] += a[up][i];
		up ^= 1, down ^= 1;
	}

	int dest;
	scanf("%d", &dest);

	printf("%lld\n", a[up][dest]);

	return 0;
}
#include <cstdio>

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);

	int num[97] = { 0, };

	n = n%p;
	int temp = n;

	int k = 1;
	while (!num[temp])
	{
		num[temp] = k++;
		temp = (temp*n) % p;
	}

	printf("%d\n", k - num[temp]);
	return 0;
}
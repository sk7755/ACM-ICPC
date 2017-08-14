#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int cnt = 0;
	
	int i;
	if (n % 2)
		i = 1;
	else
		i = 2;
	for (; i*i < n; i+=2)
	{
		if (!(n%i) && (n/i)%2 == n%2)
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
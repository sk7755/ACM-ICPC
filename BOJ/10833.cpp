#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int a, b,r=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		r += b %a;
	}

	printf("%d\n", r);

	return 0;
}
#include <cstdio>

int main()
{
	int t;

	scanf("%d", &t);

	int a = t / 300;
	t %= 300;
	int b = t / 60;
	t %= 60;
	int c = t/10;

	if (t % 10)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d %d %d\n", a,b,c);

	return 0;
	
}
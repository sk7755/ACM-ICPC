#include <cstdio>

int main()
{
	int v, a, b;

	scanf("%d %d %d", &a, &b, &v);

	int day = (v-a) / (a-b);

	if ((v - a) % (a - b))
		day++;

	printf("%d\n", day + 1);

	return 0;
}
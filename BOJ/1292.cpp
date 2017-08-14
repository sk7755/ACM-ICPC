#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int i = 1;

	while ((i*(i + 1))>>1 < a)
		i++;
	
	int sum = -i*(i + 1) / 2 * (2 * i + 1) / 3;

	sum += ((i*(i + 1) / 2) - a + 1) * i;

	while ((i*(i + 1)) >> 1 < b)
		i++;

	sum += i*(i + 1) / 2 * (2 * i + 1) / 3;

	sum -= (i*(i + 1) / 2 - b )*i;


	printf("%d\n", sum);

	return 0;
	
}
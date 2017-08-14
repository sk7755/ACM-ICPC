#include <cstdio>

int main()
{
	int n = 9, m = 'F' - 'A';
	int y;
	scanf("%d", &y);

	n = (n + y - 2013)%10;
	m = (m + y - 2013)%12;

	if (n < 0)
		n += 10;
	if (m < 0)
		m += 12;

	printf("%c%d\n", m + 'A', n);

	return 0;
}
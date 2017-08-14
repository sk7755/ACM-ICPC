#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	if (n%7 == 2 || n%7 == 0)
		printf("CY\n");
	else
		printf("SK\n");

	return 0;
}
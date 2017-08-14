#include <cstdio>
#include <cstring>

int main()
{
	char a[10001], b[10001];

	scanf("%s %s", a, b);
	int aLen = strlen(a);
	int bLen = strlen(b);

	long long A = 0, B = 0;
	for (int i = 0; i < aLen; i++)
		A += a[i] - '0';
	for (int i = 0; i < bLen; i++)
		B += b[i] - '0';

	printf("%lld\n", A*B);

	return 0;
}
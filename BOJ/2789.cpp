#include <cstdio>
#include <cstring>

int main()
{
	int a[26] = { 0, };

	a[0] = a[1] = a[2] = a[3] = a[4] = a[6] = a['I' - 'A'] = a['M' - 'A'] = a['R' - 'A'] = 1;

	char str[101];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (!a[str[i] - 'A'])
			printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
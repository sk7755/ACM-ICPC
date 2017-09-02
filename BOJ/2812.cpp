#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	char str[500001];
	int top = -1;
	scanf("%s", str);

	for (int i = 0; i < n; i++)
	{
		while (k && top >= 0 && str[top] < str[i])
		{
			top--;
			k--;
		}
		str[++top] = str[i];
	}
	str[++top - k] = '\0';
	printf("%s\n", str);

	return 0;
}
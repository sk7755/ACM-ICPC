#include <cstdio>

int main()
{
	int n;
	char str[31];
	int a[26] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		a[str[0] - 'a']++;
	}

	int flag = 1;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] > 4)
			printf("%c", i + 'a') , flag = 0;
	}

	if (flag)
		printf("PREDAJA\n");

}
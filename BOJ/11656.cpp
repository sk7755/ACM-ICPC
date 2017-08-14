#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int mycmp(char* a, char* b)
{
	if (strcmp(a, b) < 0)
		return 1;
	else
		return 0;
}

int main()
{
	char str[1001];
	char* a[1000];

	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
		a[i] = str + i;

	sort(a, a + len, mycmp);

	char ans[600000] = { 0, };

	int k = 0;
	for (int i = 0; i < len; i++)
	{
		int len = strlen(a[i]);
		for (int j = 0; j < len; j++)
			ans[k++] = a[i][j];
		ans[k++] = '\n';
	}
	ans[k++] = '\0';
	printf("%s", ans);

	return 0;
}
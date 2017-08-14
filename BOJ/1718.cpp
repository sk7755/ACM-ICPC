#include <cstdio>
#include <cstring>

int main()
{
	char str[30001];
	gets(str);
	char crp[30001];
	gets(crp);

	int len_str = strlen(str);
	int len_crp = strlen(crp);

	for (int i = 0; i < len_str; i++)
	{
		if (str[i] == ' ')
			continue;

		int j = i % len_crp;

		str[i] = (str[i] - crp[j] - 1) % 26;
		if (str[i] < 0)
			str[i] += 26;
		str[i] += 'a';
	}
	printf("%s\n", str);
}
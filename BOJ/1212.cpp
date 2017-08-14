#include <cstdio>
#include <cstring>

int main()
{
	char str[333335];
	char buffer[1300000];
	int k = 0;

	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		buffer[k++] = (((str[i] - '0') & 4)>>2) + '0';
		buffer[k++] = (((str[i] - '0') & 2)>>1) + '0';
		buffer[k++] = ((str[i] - '0') & 1 )+ '0';
	}

	buffer[k++] = '\0';

	int j = 0;
	if (buffer[0] == '0')
	{
		j++;
		if (buffer[1] == '0')
			j++;
	}
	printf("%s\n", buffer + j);

	return 0;
	
}
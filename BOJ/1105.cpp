#include <cstdio>
#include <cstring>

int main()
{
	char l[12], r[12];

	scanf("%s %s", l, r);

	int len_l = strlen(l);
	int len_r = strlen(r);

	if (len_l != len_r)
		printf("0\n");
	else
	{
		int n = 0;
		for (int i = 0; i < len_l; i++)
		{
			if (l[i] == r[i])
			{
				if (l[i] == '8')
					n++;
			}
			else
				break;
		}
		printf("%d\n", n);
	}

	return 0;
}
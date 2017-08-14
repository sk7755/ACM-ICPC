#include <cstdio>

int s[21] = { 0, };

int main()
{
	int t;
	scanf("%d", &t);

	char op[20];
	while (t--)
	{
		scanf("%s", op);

		if (op[0] == 'a')
		{
			if (op[1] == 'd')
			{
				int tmp;
				scanf("%d", &tmp);
				s[tmp] = 1;
			}
			else
			{
				for (int i = 1; i <= 20; i++)
					s[i] = 1;
			}
		}
		if (op[0] == 'r')
 		{
			int tmp;
			scanf("%d", &tmp);

			s[tmp] = 0;
		}
		if (op[0] == 'c')
		{
			int tmp;
			scanf("%d", &tmp);
			int p = 0;
			if (s[tmp])
				p = 1;
			printf("%d\n", p);
		}
		if (op[0] == 't')
		{
			int tmp;
			scanf("%d", &tmp);

			s[tmp] ^= 1;
		}
		if (op[0] == 'e')
		{
			for (int i = 1; i <= 20; i++)
				s[i] = 0;
		}
	}
}
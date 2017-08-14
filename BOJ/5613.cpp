#include <cstdio>

int main()
{
	int a;
	char op[2];
	scanf("%d", &a);
	
	while (true)
	{
		int tmp;
		scanf("%s", op);

		if (op[0] == '=')
			break;

		scanf("%d", &tmp);
		if (op[0] == '+')
			a += tmp;
		else if (op[0] == '-')
			a -= tmp;
		else if (op[0] == '*')
			a *= tmp;
		else if (op[0] == '/')
			a /= tmp;
	}

	printf("%d\n", a);

	return 0;
}
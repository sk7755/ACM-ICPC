#include <cstdio>

int check(int a, int b, char op[]);

int main()
{
	int i = 0;
	while (++i)
	{
		char op[3];
		int a, b;
		scanf("%d %s %d", &a, op, &b);

		if (op[0] == 'E')
			return 0;

		printf("Case %d: ",i);
		
		if (check(a, b, op))
			printf("true\n");
		else
			printf("false\n");
	}

	return 0;
}

int check(int a, int b, char op[])
{
	if (op[0] == '!')
		return a != b;
	if (op[0] == '<')
	{
		if (op[1] == '=')
			return a <= b;
		else
			return a < b;
	}
	if (op[0] == '>')
	{
		if (op[1] == '=')
			return a >= b;
		else
			return a>b;
	}
	if (op[0] == '=')
		return a == b;
}
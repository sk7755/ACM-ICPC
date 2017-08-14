#include <cstdio>
#include <cstring>

int main()
{
	int top;

	int t;
	
	scanf("%d", &t);

	char ps[51];

	while (t--)
	{
		top = -1;
		scanf("%s", ps);

		for (int i = 0; i < strlen(ps) && top >= -1; i++)
		{
			if (ps[i] == '(')
				top++;
			else
				top--;
		}
		
		if (top == -1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
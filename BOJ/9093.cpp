#include <cstdio>
#include <cstring>

inline void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

int main()
{
	int t;

	scanf("%d", &t);

	getchar();

	char buf[1001];
	int top = -1;
	while (t--)
	{
		char c;
		while ((c = getchar()) != '\n')
		{
			if (c != ' ')
				buf[++top] = c;
			else
			{
				while (top >= 0)
					printf("%c", buf[top--]);
				printf(" ");
			}
		}
		while (top >= 0)
			printf("%c", buf[top--]);
		printf("\n");
	}

	return 0;
}
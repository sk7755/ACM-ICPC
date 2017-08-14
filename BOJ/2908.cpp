#include <cstdio>

inline void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

int main()
{
	char a[4], b[4];

	scanf("%s %s", a, b);

	swap(a[0], a[2]);
	swap(b[0], b[2]);

	for (int i = 0; i < 3; i++)
	{
		if (a[i] < b[i])
		{
			printf("%s\n", b);
			return 0;
		}
		else if (a[i] > b[i])
		{
			printf("%s\n", a);
			return 0;
		}
	}
	
}
#include <cstdio>

inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 5-i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				for (int k = 0; k < 5; k++)
					printf("%d ", a[k]);
				printf("\n");
			}
		}
	}
}
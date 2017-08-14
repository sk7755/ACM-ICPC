#include <cstdio>

int main()
{
	int max = 0;
	int m_i, m_j;
	int a;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			scanf("%d", &a);

			if (a>max)
				max = a, m_i = i, m_j = j;
		}
	}

	printf("%d\n%d %d\n", max, m_i, m_j);

	return 0;
}
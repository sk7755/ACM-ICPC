#include <cstdio>

int main()
{
	int n;

	scanf("%d", &n);

	int a, b = 0;
	int score = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);

		if (a == 1)
		{
			if (b >0)
				score += b + 1;
			else
				score++;
			b++;
		}
		else
			b = 0;
	}

	printf("%d\n", score);

	return 0;
}
#include <cstdio>

int main()
{
	int s=0, t=0;

	for (int i = 0; i < 4; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		s += tmp;
	}
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		t += tmp;
	}

	if (s < t)
		printf("%d\n", t);
	else
		printf("%d\n", s);

	return 0;
}
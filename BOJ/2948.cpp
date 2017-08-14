#include <cstdio>

int main()
{
	int td[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

	int m, d;

	scanf("%d %d", &d, &m);

	int diff = 0;
	for (int i = 1; i < m; i++)
		diff += td[i];
	diff += d - 1;
	diff %= 7;

	switch (diff)
	{
	case 0: printf("Thursday\n");
		break;
	case 1: printf("Friday\n");
		break;

	case 2: printf("Saturday\n");
		break;

	case 3: printf("Sunday\n");
		break;

	case 4: printf("Monday\n");
		break;

	case 5: printf("Tuesday\n");
		break;
	case 6: printf("Wednesday\n");
	}

	return 0;
}
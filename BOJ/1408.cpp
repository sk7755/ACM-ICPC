#include <cstdio>

int main()
{
	char cur[9];
	char start[9];

	scanf("%s", cur);
	scanf("%s", start);

	int cur_t[3], start_t[3];

	for (int i = 0; i <= 6; i += 3)
	{
		cur_t[i / 3] = (cur[i] - '0') * 10 + (cur[i + 1] - '0');
		start_t[i / 3] = (start[i] - '0') * 10 + (start[i + 1] - '0');
	}

	int borrow = 0;
	for (int i = 2; i >= 0; i--)
	{
		start_t[i] -= cur_t[i] +borrow;

		if (start_t[i] < 0)
		{
			borrow = 1;
			if (i == 0)
				start_t[i] += 24;
			else
				start_t[i] += 60;
		}
		else
			borrow = 0;
	}

	printf("%02d:%02d:%02d\n", start_t[0], start_t[1], start_t[2]);

	return 0;
}
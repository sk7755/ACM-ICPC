#include <cstdio>

int main()
{
	int num[10001] = { 0, };

	for (int i = 1; i <= 10000; i++)
	{
		int temp = i;
		int self_num = i;
		while (temp)
		{
			self_num += temp % 10;
			temp /= 10;
		}

		if (self_num <= 10000)
		{
			num[self_num] = 1;
		}
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!num[i])
			printf("%d\n", i);
	}
}
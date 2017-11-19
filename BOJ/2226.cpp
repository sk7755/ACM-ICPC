#include <cstdio>

enum {m = 1000000000, size = 40};

class DP
{
public:
	int data[size];
	int power[size];

	DP()
	{
		for (int i = 0; i < size; i++)
			data[i] = power[i] =0;
		power[0] = 1;
	}

	void next()
	{
		int borrow = 0;
		for (int i = 0; i < size; i++)
		{
			data[i] = power[i] - data[i] - borrow;
			if (data[i] < 0)
			{
				data[i] += m;
				borrow = 1;
			}
			else
				borrow = 0;
		}

		int carry = 0;
		for (int i = 0; i < size; i++)
		{
			long long tmp = (long long)power[i] * 2 + carry;
			if (tmp >= m)
			{
				tmp -= m;
				carry = 1;
			}
			else
				carry = 0;
			power[i] = tmp;
		}
	}

	void print()
	{
		int i = size -1;
		while (data[i] == 0)
			i--;

		printf("%d", data[i--]);
		while (i >= 0)
			printf("%09d", data[i--]);
		printf("\n");
	}

};

int main()
{
	int n;
	scanf("%d", &n);
	DP dp;

	for (int i = 1; i < n; i++)
		dp.next();
	
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}

	dp.print();
	
}
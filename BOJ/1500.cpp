#include <cstdio>

enum{base = 1000000000};

class large_int
{
public:
	int a[4];

	large_int(int init = 0)
	{
		for (int i = 0; i < 3; i++)
			a[i] = 0;
		a[3] = init;
	}

	large_int& operator *= (int n)
	{
		int carry = 0;
		for (int i = 3; i >= 0; i--)
		{
			long long tmp = a[i];
			tmp = tmp* n + carry;
			if (tmp >= base)
			{
				a[i] = tmp % base;
				carry = tmp / base;
			}
			else
			{
				a[i] = tmp;
				carry = 0;
			}
		}
		return *this;
	}

	void print()
	{
		int i = 0;
		while (!a[i])
			i++;
		printf("%d", a[i++]);
		for (; i < 4; i++)
			printf("%09d", a[i]);
		printf("\n");
	}
};

int main()
{
	int s, k;
	scanf("%d %d", &s, &k);
	int d = s / k;
	large_int ans(1);
	while (s%k)
	{
		ans *= d + 1;
		s -= d + 1;
		k--;
	}

	for (int i = 0; i < s / d; i++)
		ans *= d;

	ans.print();

	return 0;
}
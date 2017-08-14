#include <cstdio>

enum{size = 10, base = 1000000000};

class big_int
{
private:
	int a[size];
public:
	big_int(int init = 0)
	{
		for (int i = 0; i < size; i++)
			a[i] = 0;
		a[size - 1] = init;
	}

	big_int& operator=(const big_int& rhs)
	{
		for (int i = 0; i < size; i++)
			a[i] = rhs.a[i];

		return *this;
	}

	big_int& operator=(int rhs)
	{
		for (int i = 0; i < size; i++)
			a[i] = 0;
		a[size - 1] = rhs;

		return *this;
	}

	big_int operator+(const big_int& rhs)
	{
		big_int ret;

		int carry = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			ret.a[i] = a[i] + rhs.a[i] + carry;
			if (ret.a[i] >= base)
				ret.a[i] -= base, carry = 1;
			else
				carry = 0;
		}

		return ret;
	}

	void print()
	{
		int i= 0;
		while (a[i] == 0)
			i++;
		printf("%d", a[i++]);
		for (; i < size; i++)
			printf("%09d", a[i]);
	}
};

int main()
{
	big_int f[251];

	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i <= 250; i++)
		f[i] = f[i - 1] + f[i - 2] + f[i - 2];

	int n;
	while (scanf("%d",&n)>0)
	{
		f[n].print();
		printf("\n");
	}

	return 0;
}
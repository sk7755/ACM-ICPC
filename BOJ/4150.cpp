#include <cstdio>

enum{ base = 1000000000 };

class large_int
{
private:
	int a[112];
public:
	void init(int n)
	{
		for (int i = 0; i < 111; i++)
			a[i] = 0;
		a[111] = n;
	}

	void print()
	{
		int i = 0;
		while (!a[i])
			i++;

		printf("%d", a[i++]);
		for (; i < 112; i++)
			printf("%09d", a[i]);
		printf("\n");
	}

	large_int& operator+=(large_int& rhs)
	{
		int carry = 0;
		for (int i = 111; i >= 0; i--)
		{
			a[i] += rhs.a[i] + carry;
			if (a[i] >= base)
				a[i] -= base, carry = 1;
			else
				carry = 0;
		}
		return *this;
	}
};

int main()
{
	large_int f[2];
	int prev = 0, cur = 1;

	f[0].init(0);
	f[1].init(1);

	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		f[prev] += f[cur];
		prev ^= 1, cur ^= 1;
	}

	f[cur].print();

	return 0;
}
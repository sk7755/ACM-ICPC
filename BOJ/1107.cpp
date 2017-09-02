//존나 막코딩;

#include <cstdio>

inline int min(int a, int b)
{
	return a > b ? b : a;
}

int abs(int x);
int count_cipher(int x);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int num[10] = { 0, };
	int ans = abs(100 - n);

	for (int i = 0; i < m; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		num[tmp] = 1;
	}

	if (m == 10)
	{
		printf("%d\n", ans);
		return 0;
	}

	int cipher = count_cipher(n);
	int digit = 1;

	for (int i = 1; i < cipher; i++)
		digit *= 10;

	int flag = 1;
	int s = 0;
	for (; digit != 0; digit /= 10)
	{
		int c = n / digit;
		
		int up = -1, down = -1;
		for (int i = c + 1; i < 10; i++)
		{
			if (!num[i])
			{
				up = i;
				break;
			}
		}

		if (s == 0 && up == -1 && !num[1])
		{
			if (!num[0])
				up = 10;
			else
				up = 11;
		}

		if (up != -1)
		{
			int lower;
			for (int i = 0; i < 10; i++)
			{
				if (!num[i])
				{
					lower = i;
					break;
				}
			}
			int tmp = up*digit;
			for (int i = digit / 10; i >= 1; i /= 10)
				tmp += i*lower;
			cipher = count_cipher(s + tmp);
			ans = min(ans, abs(n - tmp) + cipher);
		}

		for (int i = c - 1; i >= 0; i--)
		{
			if (!num[i])
			{
				down = i;
				break;
			}
		}
		int tmp_digit = digit;
		if (s == 0  &&n>=10&& down == -1)
			down = 0, tmp_digit/10;

		if (down != -1)
		{
			int upper;
			for (int i = 9; i >=0; i--)
			{
				if (!num[i])
				{
					upper = i;
					break;
				}
			}
			int tmp = down*tmp_digit;
			for (int i = tmp_digit / 10; i >= 1; i /= 10)
				tmp += i*upper;

			cipher = count_cipher(s + tmp);
			ans = min(ans, abs(n- tmp) + cipher);
		}

		n -= c*digit;
		s += c*digit;

		if (num[c])
		{
			flag = 0;
			break;
		}

	}

	if (flag)
		ans = min(ans, count_cipher(s+n));

	printf("%d\n", ans);

	return 0;

}

int abs(int x)
{
	if (x < 0)
		x = -x;

	return x;
}

int count_cipher(int x)
{
	int ret = 0;

	if (x == 0)
		return 1;

	while (x)
	{
		x /= 10;
		ret++;
	}

	return ret;
}
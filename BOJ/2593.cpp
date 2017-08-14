#include <cstdio>

struct quary
{
	int n;
	int strike;
	int ball;
};

int checker(int a);

quary q[100];
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &q[i].n, &q[i].strike, &q[i].ball);
	}

	int ans = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				if (i != j && j!= k && i != k)
					ans += checker(i * 100 + j * 10 + k);
			}
		}
	}

	printf("%d\n", ans);
}

int checker(int a)
{
	int cnt[10] = { 0, };
	int tmp = a;
	while (tmp)
	{
		cnt[tmp % 10]++;
		tmp /= 10;
	}


	for (int i = 0; i < n; i++)
	{
		int strike = 0, ball = 0;
		int ans = a;
		int question = q[i].n;

		for (int i = 0; i < 3; i++)
		{
			if (ans % 10 == question % 10)
				strike++;
			else if (cnt[question % 10])
				ball++;
			ans /= 10, question /= 10;
		}

		if (strike != q[i].strike || ball != q[i].ball)
			return 0;
	}

	return 1;
}
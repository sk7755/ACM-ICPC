#include <cstdio>

int main()
{
	int number[100001] = { 0, };

	number[0] = number[1] = 1;
	for (int i = 4; i <= 100000; i += 2)
	{
		number[i] = 1;
	}

	for (int i = 3; i <= 333;i+=2)
	{
		if (!number[i])
		{
			for (int j = i*i; j <= 100000; j += i)
				number[j] = 1;
		}
	}

	int a[100001] = { 0, };

	for (long long i = 2; i <= 100000; i *= 2)
	{
		for (long long j = i; j <= 100000; j += i)
		{
			a[j]++;
		}
	}

	for (long long i = 3; i <= 100000; i += 2)
	{
		if (!number[i])
		{
			for (long long j = i; j <= 100000; j *= i)
			{
				for (long long k = j; k <= 100000; k += j)
					a[k]++;
			}
		}
	}

	int A, B;

	scanf("%d %d", &A, &B);

	int ans = 0;
	for (int i = A; i <= B; i++)
	{
		if (!number[a[i]])
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
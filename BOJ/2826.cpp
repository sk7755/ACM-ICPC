//몇번 나열해보니 피보나치 꼴이 나왔으며
//이에 대한 증명도 해보니 어렵진 않은데..
//직접 나열해보지 않고 이를 피보나치라고 생각할수있으면 진짜 천재당

#include <cstdio>

long long recursive_solve(long long fibo[], long long val);

int main()
{
	long long fibo[100] = { 0,1 };

	for (int i = 2; i <= 74; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	long long n;

	scanf("%lld", &n);

	printf("%lld\n", recursive_solve(fibo, n));

	return 0;
}

long long recursive_solve(long long fibo[], long long val)
{
	int left = 0, right = 74;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (fibo[mid] < val)
			left = mid + 1;
		else if (fibo[mid] > val)
			right = mid - 1;
		else
			return fibo[mid];
	}

	return recursive_solve(fibo, val - fibo[right]);
}
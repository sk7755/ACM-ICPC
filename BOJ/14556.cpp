/*dp[n+1] = dp[n] * (2*i+1)
dp[n]�� 2^n �߸� ���������� �δ� ����� ����� �Ҷ�, (�� ��츦 ������ ��ü ��츦 ���)
(n-1)C(k-1) * dp[k-1] * (n-k)! * 2^(n-k) ���� k�� 1���� n���� ���� ���̴�. (C�� combination)
�̸� ���� �����ϰ� �����ϸ� (n-1)! / (k-1)! * dp[k-1] * 2^(n-k) �̰�,
dp[n+1]�� dp[n]�� ���踦 �鿩�� ���� �ᱹ, dp[n+1] = (2*n+1)dp[n]�� �ȴ�.

�� �� �����ⰰ�� �����Ѱ� ������, �����س� ����� ���� �����غ��� ���� ���� ���� ������ ����.
���԰� 2^1 ~ 2^n���� �߸� ������, �� �������� ���� �߸� �������� �����غ���
2^n�� �������� ���´ٸ� �������� �̹� ������ �־�� �ϹǷ� dp[n-1], �ű�ٰ� 2^n�� ���� �ۿ� �� �� �����Ƿ� 1 * dp[n-1]
2^(n-1)�� �������� ���´ٸ� �������� �̹� ������ �־�� �ϹǷ� dp[n-1], �ű�ٰ� 2^(n-1)�� �������̳� ���� �Ѵ� �� �� �����Ƿ� 2 * dp[n-1]
...
2^1�� �������� ���´ٸ� �������� �̹� ������ �־�� �ϹǷ� dp[n-1], �ű�ٰ� 2^(n-1)�� �������̳� ���� �Ѵ� �� �� �����Ƿ� 2 * dp[n-1]
�̸� ��� ��ģ ����� ���� dp[n] = (2 * n - 1) * dp[n-1]. 
*/
#include <cstdio>

int main()
{
	int m = 1000000009;
	int a = 1;
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		long long temp = a;
		temp = temp * (2 * i - 1) % m;
		a = temp;
	}


	printf("%d\n", a);

	return 0;
}
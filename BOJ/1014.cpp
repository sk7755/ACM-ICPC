#include <cstdio>

int CASE[144][10];
int dp[144] = { 0, };
int a[10];
char map[10][10];
int case_k = 0;

int check(int line, int dp_num, int m);
void CASE_make(int k);

int main()
{
	CASE_make(0);
	
	int t = 0;

	scanf("%d", &t);

	while (t--)
	{
		int n, m;//n�� ���α��� m�� ���α���

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			scanf("%s", map[i]);

		for (int i = 0; i < 144; i++)	//dp ù�� �ʱ�ȭ
		{
			dp[i] = 0;
			for (int j = 0; j < m; j++)
			{
				if (CASE[i][j] == 1 && map[n - 1][j] == '.')
					dp[i]++;
			}
		}

		int new_dp[144];

		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j < 144; j++)
				new_dp[j] = check(i, j, m);

			for (int j = 0; j < 144; j++)
				dp[j] = new_dp[j];
		}

		int max = 0;
		for (int i = 0; i < 144; i++)
		{
			if (max < dp[i])
				max = dp[i];
		}

		printf("%d\n", max);


	}
	return 0;
}

int check(int line, int dp_num, int m)
{
	//'x'�� CASE ���� �����ִ��� Ȯ��
	for (int i = 0; i < m; i++)
	{
		if (CASE[dp_num][i] == 1 && map[line][i] == 'x')
		{
			return 0;
		}
	}
	//�������� �ʴٸ� ���� �ٸ� case�� ���ؾ���
	
	int max = 0;

	for (int i = 0; i < 144; i++)
	{
		int valid = 1;

		//���� CASE�� �Ʒ��� �� �� �ִ����� ���� �˻�
		for (int j = 0; j < m; j++)
		{
			if (CASE[dp_num][j] == 1)
			{
				//�� �� ������ �����Ѵٸ�, �� case�� �ü� �ִ� case�� �ƴϾ�.
				//���� ������� ���� �Ѱܾ���.
				if ((j>0 && CASE[i][j - 1] == 1) || j < m - 1 && CASE[i][j + 1] == 1)
				{
					valid = 0;
					break;
				}
			}
		}

		if (valid)	//����� �� �ִ� case��� ��
		{
			if (dp[i] > max)
				max = dp[i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (CASE[dp_num][i] == 1)
			max++;
	}

	return max;

}

void CASE_make(int k)
{
	if (k == 10)
	{
		for (int i = 0; i<10; i++)
		{
			CASE[case_k][i] = a[i];
		}
		case_k++;
		return;
	}

	if (k == 0 || !a[k - 1])
	{
		a[k] = 1;
		CASE_make(k + 1);
	}

	a[k] = 0;
	CASE_make(k + 1);

	return;
}
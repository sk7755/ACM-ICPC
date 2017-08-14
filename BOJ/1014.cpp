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
		int n, m;//n이 세로길이 m이 가로길이

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			scanf("%s", map[i]);

		for (int i = 0; i < 144; i++)	//dp 첫항 초기화
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
	//'x'와 CASE 쪽이 겹쳐있는지 확인
	for (int i = 0; i < m; i++)
	{
		if (CASE[dp_num][i] == 1 && map[line][i] == 'x')
		{
			return 0;
		}
	}
	//겹쳐있지 않다면 이제 다른 case랑 비교해야함
	
	int max = 0;

	for (int i = 0; i < 144; i++)
	{
		int valid = 1;

		//다음 CASE가 아래에 올 수 있는지에 대한 검사
		for (int j = 0; j < m; j++)
		{
			if (CASE[dp_num][j] == 1)
			{
				//이 두 조건을 만족한다면, 이 case는 올수 있는 case가 아니야.
				//따라서 계산하지 말고 넘겨야함.
				if ((j>0 && CASE[i][j - 1] == 1) || j < m - 1 && CASE[i][j + 1] == 1)
				{
					valid = 0;
					break;
				}
			}
		}

		if (valid)	//계산할 수 있는 case라는 뜻
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
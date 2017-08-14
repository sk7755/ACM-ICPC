#include <cstdio>

inline void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	int n;
	int p[3][3] = { 0, };
	int sum[3] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int a;
			scanf("%d", &a);

			p[j][a - 1]++;
		}
	}

	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		sum[i] = p[i][0] + p[i][1] * 2 + p[i][2] * 3;
		if (max < sum[i])
			max = sum[i];
	}

	long long new_score[3];
	
	for (int i = 0; i < 3; i++)
	{
		new_score[i] = sum[i];
		new_score[i] *= 10000;
		new_score[i] += p[i][2];
		new_score[i] *= 10000;
		new_score[i] += p[i][1];
	}

	int president = 0;
	if (new_score[0] > new_score[1] && new_score[0] > new_score[2])
		president = 1;
	else if (new_score[1] > new_score[2] && new_score[1] > new_score[0])
		president = 2;
	else if (new_score[2] > new_score[1] && new_score[2] > new_score[0])
		president = 3;

	printf("%d %d\n", president, max);
}
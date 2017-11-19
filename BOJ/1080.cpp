//�̸� �����ϱ� ���ؼ��� 00000 �� �ٽ� 00000���� �ٲ� �� �ִ°��� ���� �����غ���.
//00000�� �ٽ� 00000���� �ҷ��� ������ ���� �ߺ��� �� �ۿ� ���µ� �̴� optimal�� ���
//���� �̸� �ǵ��� ���ƾ� �Ѵ�. 00000�κ��� �ǵ��� �ʴ´ٸ� �� �� 1�� �ǵ���� �ϹǷ�
//�Ʒ��� ���� �ڵ�� �׻� optimal solution�� �����Ѵ�. ( �����Ѵٸ� )
//row�� ��쵵 ���������� ������ �� �ִ�. 

#include <cstdio>

int main()
{
	int n, m;
	char a[50][51] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		char str[51];
		scanf("%s", str);
		for (int j = 0; j < m; j++)
		{
			if (str[j] == a[i][j])
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}

	if (n < 3 || m < 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1)
				{
					printf("-1\n");
					return 0;
				}
			}
		}
		printf("0\n");
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] == 1)
			{
				for (int s = 0; s < 3; s++)
				{
					for (int t = 0; t < 3; t++)
						a[i + s][j + t] ^= 1;
				}
				ans++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", ans);
}
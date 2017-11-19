//이를 증명하기 위해서는 00000 을 다시 00000으로 바꿀 수 있는가에 대해 생각해본다.
//00000을 다시 00000으로 할려면 연산을 동일 중복할 수 밖에 없는데 이는 optimal에 모순
//따라서 이를 건들지 말아야 한다. 00000부분은 건들지 않는다면 그 옆 1을 건드려야 하므로
//아래와 같은 코드는 항상 optimal solution을 생성한다. ( 존재한다면 )
//row의 경우도 마찬가지로 증명할 수 있다. 

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
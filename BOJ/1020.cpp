#include <cstdio>
#include <cstring>

long long passing_time(char *from, char *to, int n);

int main()
{
	int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };

	char str[16];
	char orig[16];

	scanf("%s", str);

	strcpy(orig, str);
	int n = strlen(str);

	int sum[16] = { 0, };

	for (int i = n - 1; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + a[str[i] - '0'];
	}

	int diff, diff2;

	for (int i = n - 1; i >= 0; i--)
	{
		for (char cur = str[i]+ 1; cur <= '9'; cur++)
		{
			diff = a[str[i] - '0'] - a[cur - '0'];
			
			if (( 2 * (n - 1 - i) <= sum[i + 1] + diff ) && ( sum[i + 1] + diff <= 7 * (n - 1 - i) ))
			{
				//�������� �ٲٴ°� �����ϴٴ°�
				//�׷� �ٲ����
				str[i] = cur;

				for (int j = i + 1; j < n; j++)
				{
					//j�� �ڸ���
					for (int k = 0; k <= 9; k++)
					{
						diff2 = diff + a[str[j] - '0'] - a[k];
						if ((2 * (n -1 - j) <= sum[j + 1] + diff2) && (sum[j + 1] + diff2 <= 7 * (n - 1 - j)))
						{
							str[j] = k + '0';
							diff = diff2;
							break;
						}
					}
				}
				//�ٲٱ� �Ϸ�

				printf("%lld\n", passing_time(orig,str,n));
				return 0;
			}
		}
	}
	//������� ���´ٸ� �Ұ����Ѱ�


	for (int i = 0; i < n; i++)
	{
		for (char cur = '0'; cur <= str[i]; cur++)
		{
			diff = a[str[i] - '0'] - a[cur - '0'];

			if ((2 * (n - 1 - i) <= sum[i+1] + diff) && (sum[i+1] + diff <= 7 * (n - 1 - i)))
			{
				//�������� �ٲٴ°� �����ϴٴ°�
				//�׷� �ٲ����
				str[i] = cur;

				for (int j = i + 1; j < n; j++)
				{
					//j�� �ڸ���
					for (int k = 0; k <= 9; k++)
					{
						diff2 = diff + a[str[j] - '0'] - a[k];
						if ((2 * (n - 1 - j) <= sum[j+1] + diff2) && (sum[j+1] + diff2 <= 7 * (n - 1 - j)))
						{
							str[j] = k + '0';
							diff = diff2;
							break;
						}
					}
				}
				//�ٲٱ� �Ϸ�
				printf("%lld\n", passing_time(orig, str, n));
				return 0;
			}
		}
	}

}

long long passing_time(char *from, char *to, int n)
{
	long long f = 0,t = 0;
	int b = 0;

	for (int i = 0; i < n; i++)
	{
		f *= 10;
		f += from[i];
		t *= 10;
		t += to[i];
	}

	long long r = t - f;

	if (r <= 0)
	{
		long long temp = 1;
		for (int i = 0; i < n; i++)
			temp *= 10;
		r += temp;
	}

	return r;
}
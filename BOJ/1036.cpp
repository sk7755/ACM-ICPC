#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct num
{
	int d;
	int cnt[60];
};

int cmp(num& a, num& b)
{
	int tmp_a[60], tmp_b[60];
	int carry_a = 0, carry_b = 0;
	for (int i = 0; i < 60; i++)
	{
		tmp_a[i] = a.cnt[i] * (35 - a.d) + carry_a;
		tmp_b[i] = b.cnt[i] * (35 - b.d) + carry_b;

		if (tmp_a[i] >= 36)
		{
			carry_a = tmp_a[i] / 36;
			tmp_a[i] %= 36;
		}
		else
			carry_a = 0;

		if (tmp_b[i] >= 36)
		{
			carry_b = tmp_b[i] / 36;
			tmp_b[i] %= 36;
		}
		else
			carry_b = 0;
	}

	for (int i = 59; i >= 0; i--)
	{
		if (tmp_a[i] != tmp_b[i])
			return tmp_a[i] > tmp_b[i];
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	char str[51];
	num arr[36] = { 0, };

	for (int i = 0; i < 36; i++)
		arr[i].d = i;

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);

		for (int s = len - 1, j = 0; s >= 0; s--,j++)
		{
			if (str[s] < 'A')
				arr[str[s] - '0'].cnt[j]++;
			else
				arr[str[s] - 'A'+10].cnt[j]++;
		}
	}

	for (int i = 0; i < 36; i++)
	{
		int carry = 0;
		for (int j = 0; j < 60; j++)
		{
			arr[i].cnt[j] += carry;
			if (arr[i].cnt[j] >= 36)
			{
				arr[i].cnt[j] -= 36;
				carry = 1;
			}
			else
				carry = 0;
		}
	}

	sort(arr, arr + 36, cmp);

	int k;
	scanf("%d", &k);

	for (int i = 0;i<36;i++)
	{
		if (k)
		{
			arr[i].d = 35;
			k--;
		}
	}

	int ans[60] = { 0, };

	int carry = 0;
	for (int i = 0; i < 60; i++)
	{
		ans[i] = carry;
		for (int j = 0; j < 36; j++)
		{
			ans[i] += arr[j].cnt[i] * arr[j].d;
		}

		if (ans[i] >= 36)
		{
			carry = ans[i] / 36;
			ans[i] %= 36;
		}
		else
			carry = 0;
	}

	int i = 59;
	while (i >= 0 && ans[i] == 0)
		i--;

	if (i == -1)
	{
		printf("0\n");
		return 0;
	}

	for (; i >= 0; i--)
	{
		if (ans[i] < 10)
			printf("%c", ans[i] + '0');
		else
			printf("%c", ans[i] + 'A' - 10);
	}

	return 0;
}
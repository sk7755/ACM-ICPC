#include <cstdio>
#include <cstring>

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		char n[7];
		char r[8];
		scanf("%s", n);
		int len = strlen(n);

		int carry = 0;
		for (int i = len - 1; i >=0; i--)
		{
			r[i+1] = n[i] + n[len - 1 - i] + carry - '0';
			
			if (r[i+1] >'9')
				r[i+1] -= 10, carry = 1;
			else
				carry = 0;
		}
		if (carry)
		{
			r[0] = carry + '0';
			len++;
		}
		else
		{
			for (int i = 0; i < len; i++)
				r[i] = r[i + 1];
		}
		int ans = 1;
		for (int i = 0; i < len; i++)
		{
			if (r[i] != r[len - 1 - i])
			{
				ans = 0;
				break;
			}
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
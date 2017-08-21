#include <cstdio>
#include <cstring>

int main()
{
	char str[1000001];
	int n;

	scanf("%d", &n);
	scanf("%s", str);
	
	int target = 1;
	int ans = 0;
	for (int i = n - 1; i >= 0;)
	{
		if (str[i] - 'A' == target)
		{
			ans++;
			int cnt = 0;
			while (i >= 0 && str[i] - 'A' == target)
				cnt++, i--;
			if (cnt != 1)
				target ^= 1;
		}
		else
			i--;
	}

	printf("%d\n", ans);
}
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	char str[13];
	int flag[10] = { 0, };
	long long w[10] = { 0, };
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);

		long long mask = 1;
		for (int j = len-1;j>=0;j--, mask*=10)
			w[str[j] - 'A'] += mask;
		flag[str[0] - 'A']++;
	}

	int zero = -1;
	long long min = 10000000000000;
	for (int i = 0; i < 10; i++)
	{
		if (!flag[i] && w[i] < min)
		{
			zero = i;
			min = w[i];
		}
	}
	
	w[zero] = 0;

	long long ans = 0;
	sort(w, w + 10);

	for (int i = 0; i < 10; i++)
	{
		ans += (long long)i*w[i];
	}

	printf("%lld\n", ans);
}
/*�볪�� �ǳʶٱ�
�迭�� ������ �ּҷ� �ϴ� ������ ���ϴ� ���α׷�
�׸��� �˰���
*/
#include <cstdio>
#include <algorithm>

using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	scanf("%d", &t);

	int a[10000];
	while (t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		sort(a, a + n);

		int ans = 0;
		for (int i = 0; i + 2 < n; i ++)
		{
			ans = max(ans, a[i + 2] - a[i]);
		}

		printf("%d\n", ans);
	}
}
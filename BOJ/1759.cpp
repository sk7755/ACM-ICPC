#include <cstdio>
#include <algorithm>

void permutation(char a[], int i, int n, int v, int w);

int l, c;

int main()
{

	scanf("%d %d", &l, &c);
	getchar();
	char a[15];
	for (int i = 0; i < c; i++)
		a[i] = getchar(), getchar();

	std::sort(a, a + c);

	permutation(a, 0,0,0,0);
}

char str[16];

//i는 현재 a에서 보는곳
//n은 현재 str에 저장된 문자열 개수
void permutation(char a[], int i, int n, int v, int w)
{
	if (i == c)
	{
		if (n == l && v >=1 && w>=2)
		{
			str[n] = '\0';
			printf("%s\n", str);
		}
		return;
	}
	int new_v=v, new_w=w;
	str[n] = a[i];
	if (str[n] == 'a' || str[n] == 'e' || str[n] == 'i' || str[n] == 'o' || str[n] == 'u')
		new_v++;
	else
		new_w++;
	permutation(a, i + 1, n+1, new_v, new_w);
	permutation(a, i + 1, n, v, w);

	return;
}
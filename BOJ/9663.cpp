#include <cstdio>

int ans = 0;
int col[15] = { 0, };
int Pdiag[30] = { 0, };
int Ndiag[30] = { 0, };
int n;

void solver(int r);

int main()
{
	scanf("%d", &n);

	solver(0);

	printf("%d\n", ans);
}

void solver(int r)
{
	if (r == n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!Pdiag[r + i] && !Ndiag[r - i + n - 1] && !col[i])
		{
			Pdiag[r + i] = 1, Ndiag[r - i + n - 1] = 1, col[i] = 1;
			solver(r + 1);
			Pdiag[r + i] = 0, Ndiag[r - i + n - 1] = 0, col[i] = 0;
		}
	}
}
//세그트리, 팬윅트리.. +몇인지 기록해주기 위해서..
//대체 이게 뭘 의미하는 걸까
#include <cstdio>
#include <algorithm>
int bubblesort(int A[], int N);

using namespace std;

class element
{
public:
	int idx;
	int data;

	element(int idx = 0, int data = 0) :idx(idx), data(data) {}

};

bool cmp(element& a, element& b)
{
	if (a.data < b.data)
	{
		return 1;
	}
	else if (a.data > b.data)
		return 0;
	else
	{
		if (a.idx < b.idx)
			return 1;
		else
			return 0;
	}
}

int main()
{
	int n;
	element a[500001];
	int b[500001];

		//scanf("%d", &n);
		n = 100;
		for (int i = 1; i <= n; i++)
		{
			//scanf("%d", &a[i].data);
			a[i].data = 1;
			a[i].idx = i;
			b[i] = a[i].data;
		}
		a[50].data = 10;
		b[50] = 10;
		sort(a + 1, a + n + 1, cmp);

		int max = 0;
		for (int i = 1; i <= n; i++)
		{
			if (max < a[i].idx - i)
				max = a[i].idx - i;
		}
		printf("%d :", max + 1);

		printf("%d\n", bubblesort(b, n));
	return 0;
}

int bubblesort(int A[], int N)
{
	int i, j, temp;
	int change;
	for (i = 1; i <= N; i++){
		change = 0;
		for (j = 1; j <= N - i; j++){
			if (A[j] > A[j + 1]){
				change = 1;
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
		if (change == 0) {
			break;
		}
	}
	return i;

}
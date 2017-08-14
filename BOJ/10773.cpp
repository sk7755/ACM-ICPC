#include <cstdio>

int main()
{
	int stack[100000];
	int top = -1;

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		if (tmp == 0)
			top--;
		else
			stack[++top] = tmp;
	}

	int sum = 0;
	for (int i = 0; i <= top; i++)
		sum += stack[i];

	printf("%d\n", sum);

	return 0;
}
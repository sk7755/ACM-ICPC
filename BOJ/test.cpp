
#include <stdio.h>

int main()
{
	char b[50001] = { 0, };
	int a[50000] = { 0, };
	int N;
	int k;

	scanf("%d", &N);
	scanf("%d", &k);
	scanf("%s", b);

	for (int i = 0; i<N; i++)
		a[i] = (int)b[i] - '0';

	int stack[2][3] = { 0, };
	int counter = 0;
	int c = -1;
	int T = k;
	for (int i = 0; i<N; i++)
	{
		for (int d = i; d <= c + k + 1; d++)
		{
			if (a[d]>stack[0][0])
			{
				stack[0][0] = a[d];
				stack[1][0] = d;
				continue;
			}
			if (a[d]>stack[0][1])
			{
				stack[0][1] = a[d];
				stack[1][1] = d;
				continue;
			}
			if (a[d]>stack[0][2])
			{
				stack[0][2] = a[d];
				stack[1][2] = d;
				continue;
			}
		}
		/*   for(int o=0;o<2;o++)
		{
		for(int p=0;p<3;p++)
		printf("%d ",stack[o][p]);
		printf("\n");
		}*/
		for (int j = stack[1][0] - 1; j>c; j--)
		{
			a[j] = -1;
			counter++;
			if (counter == T)
				break;
		}
		i = k + c +2;
		k = k + 1 + c - stack[1][0];
		c = stack[1][0];
		//   printf("\nc is %d\n",c);
		if (counter == T)
			break;
		stack[0][0] = stack[0][1];
		stack[0][1] = stack[0][2];
		stack[0][2] = 0;
		stack[1][0] = stack[1][1];
		stack[1][1] = stack[1][2];
		stack[1][2] = 0;
	}
	int L = T - counter;
	for (int i = 0; i<N - L; i++)
		if (a[i] != -1)
			printf("%d", a[i]);

}
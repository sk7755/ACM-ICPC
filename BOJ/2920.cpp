#include<cstdio>

int main()
{
	int a[9] = { 0,0,0,0,0,0,0,0,-1 };

	for (int i = 0; i < 8; i++)
		scanf("%d", &a[i]);

	int i = 1;
	if (a[0] == 1)
	{
		while (a[i] == i + 1)
			i++;
		if (i == 8)
			printf("ascending\n");
		else
			printf("mixed\n");
	}
	else if (a[0] == 8)
	{
		while (a[i] == 8 - i)
			i++;
		if (i == 8)
			printf("descending\n");
		else
			printf("mixed\n");
	}
	else
		printf("mixed\n");

	return 0;
}
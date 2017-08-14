#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int inc = 1;
	int dec = 1;
	int tmp_inc = 1;
	int tmp_dec = 1;
	int pre;
	scanf("%d", &pre);

	for (int i = 1; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		if (tmp > pre)
		{
			tmp_inc++;
			tmp_dec = 1;
		}
		else if (tmp < pre)
		{
			tmp_dec++;
			tmp_inc = 1;
		}
		else
		{
			tmp_inc++;
			tmp_dec++;
		}

		if (inc < tmp_inc)
			inc = tmp_inc;
		if (dec < tmp_dec)
			dec = tmp_dec;

		pre = tmp;
	}

	if (inc < dec)
		printf("%d\n", dec);
	else
		printf("%d\n", inc);

	return 0;
}
#include <cstdio>



int main()
{
	int person[5001];
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		person[i] = i;

	printf("<");
	int q = 1;
	while (n)
	{
		q = (q - 1 + m) % n;
		if (q == 0)
			q = n;
		printf("%d", person[q]);

		for (int i = q; i < n; i++)
			person[i] = person[i + 1];
		n--;

		if (n != 0)
			printf(", ");
	}
	printf(">\n");

	return 0;
}
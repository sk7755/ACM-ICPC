#include <cstdio>

int main()
{
	int n;
	int file[1000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &file[i]);

	int cluster;

	scanf("%d", &cluster);

	long long nCluster = 0;
	for (int i = 0; i < n; i++)
	{
		nCluster += file[i] / cluster;
		if (file[i] % cluster)
			nCluster++;
	}

	printf("%lld\n", nCluster * (long long)cluster);

	return 0;
}
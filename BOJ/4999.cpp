#include <cstdio>

int main()
{
	char jaehwan[1000];
	char doctor[1000];

	scanf("%s", jaehwan);
	scanf("%s", doctor);

	for (int i = 0; jaehwan[i] != '\0' && doctor[i] != '\0'; i++)
	{
		if (jaehwan[i] > doctor[i])
		{
			printf("no\n");
			return 0;
		}
	}

	printf("go\n");

	return 0;
}
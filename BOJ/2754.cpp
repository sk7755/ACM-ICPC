#include <cstdio>

int main()
{
	char str[3];

	scanf("%s", str);

	 double score = 4 - str[0] + 'A';

	 if (str[1] == '+')
		 score += 0.3;
	 else if (str[1] == '-')
		 score -= 0.3;

	 if (str[0] == 'F')
		 score += 1;
	 printf("%.1lf\n", score);

	 return 0;
}
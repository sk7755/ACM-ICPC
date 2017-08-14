#include <stdio.h>
#define buffer 1000

char stack[1000];
int top;

//?진수를 10진수로 변환. arr에 저장된 것을 10진수로 바꾸며 10진수를 반환한다.
int what_to_dec(int src, int *arr, int n);

int main()
{
	int i, j;
	int n;
	int arr[buffer];
	char str[buffer];
	int src, dest; //진수는 2~16까지 입력 허용 문자는 0~F 까지 허용.(단 balanced tenary 에서는 - 출력도 허용)
	int dec;


	scanf("%s", str);

	scanf("%d", &src);

	i = 0, j = 0;
	if (str[0] == '-')
		i = 1;

	while (str[i] != '\0')
	{
		if (str[i] > '9')
			arr[j++] = str[i++] - 'A' + 10;
		else
			arr[j++] = str[i++] - '0';
	}

	dec = what_to_dec(src, arr, j);
	if (str[0] == '-')
		dec = -dec;

	printf("%d\n", dec);


	return 0;

}

int what_to_dec(int src, int *arr, int n)
{
	int dec = 0;

	for (int i = 0; i<n; i++)
		dec = dec * src + arr[i];

	return dec;
}

#include <stdio.h>
#define buffer 1000

char stack[1000];
int top;

//?������ 10������ ��ȯ. arr�� ����� ���� 10������ �ٲٸ� 10������ ��ȯ�Ѵ�.
int what_to_dec(int src, int *arr, int n);

int main()
{
	int i, j;
	int n;
	int arr[buffer];
	char str[buffer];
	int src, dest; //������ 2~16���� �Է� ��� ���ڴ� 0~F ���� ���.(�� balanced tenary ������ - ��µ� ���)
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

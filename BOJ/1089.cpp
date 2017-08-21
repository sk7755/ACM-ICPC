/*
#include <cstdio>
#include <cmath>

char number[10][16] = {
	"####.##.##.####" ,	//0
	"..#..#..#..#..#",	//1
	"###..#####..###",	//2
	"###..####..####",	//3
	"#.##.####..#..#",	//4
	"####..###..####",	//5
	"####..####.####",	//6
	"###..#..#..#..#",	//7
	"####.#####.####",	//8
	"####.####..####"	//9
};


//src를 고쳐서 dest가 될 수 있으면 1 없으면 0 반환 
int IsAbleToBe(char src[], char dest[]);

int main()
{

	int n;

	scanf("%d", &n);

	char str[5][40];

	for (int i = 0; i < 5; i++)
		scanf("%s", str[i]);

	double ans = 0;
	char src[16];
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		int cnt = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 3; k++)
				src[j * 3 + k] = str[j][i * 4 + k];
		}

		for (int j = 0; j < 10; j++)
		{
			if (IsAbleToBe(src, number[j]))
			{
				sum += j;
				cnt++;
			}
		}

		if (cnt == 0)
		{
			printf("-1\n");
			return 0;
		}
		ans += sum * pow(10, n - 1 - i) / (double)cnt;
	}
	printf("%.10lf", ans);
}

int IsAbleToBe(char src[], char dest[])
{
	for (int i = 0; i < 15; i++)
	{
		if (src[i] == '#' && dest[i] == '.')
			return 0;
	}
	return 1;
}
*/

#include <cstdio>

//5*3을 한줄로 늘여서 표현
char number[10][16] = {
	"####.##.##.####" ,	//0
	"..#..#..#..#..#",	//1
	"###..#####..###",	//2
	"###..####..####",	//3
	"#.##.####..#..#",	//4
	"####..###..####",	//5
	"####..####.####",	//6
	"###..#..#..#..#",	//7
	"####.#####.####",	//8
	"####.####..####"	//9
};


//src 전구를 고쳐서 dest가 될 수 있으면 1 없으면 0 반환 
int IsAbleToBe(char src[], char dest[]);
//a^n 반환
long long MyPow(long long a, int n);

int main()
{

	int n;

	scanf("%d", &n);

	char str[5][40];

	for (int i = 0; i < 5; i++)
		scanf("%s", str[i]);

	long long int_part = 0;    //정수부
	long long float_part = 0;    //실수부
	long long precise = MyPow(10, 10);    //정확도를 위한수 10^11
	char src[16];
	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		long long cnt = 0;

		//입력받은 문자열에서 숫자 하나씩 분리, src 배열에 한줄로 저장
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 3; k++)
				src[j * 3 + k] = str[j][i * 4 + k];
		}

		for (int j = 0; j < 10; j++)
		{
			if (IsAbleToBe(src, number[j]))
			{
				sum += j;
				cnt++;
			}
		}

		if (cnt == 0)
		{
			printf("-1\n");
			return 0;
		}
		long long tmp = sum * MyPow(10, n - 1 - i);
		int_part += tmp / cnt;
		float_part += ((tmp%cnt) * precise) / cnt;    //실수부를 유효숫자 11자리까지 계산
	}
	int_part += float_part / precise;
	float_part %= precise;

	printf("%lld", int_part);
	printf(".%010lld", float_part);
}

int IsAbleToBe(char src[], char dest[])
{
	for (int i = 0; i < 15; i++)
	{
		if (src[i] == '#' && dest[i] == '.')    //src는 켜져있는데 dest는 꺼져있을 경우만 불가능
			return 0;
	}
	return 1;
}

long long MyPow(long long a, int n)
{
	long long ret = 1;
	for (int i = 0; i < n; i++)
		ret *= a;

	return ret;
}
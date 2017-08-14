#include <cstdio>

int sdoku[9][9];
int solver(int k);
int main()
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			scanf("%d", &sdoku[i][j]);
	}
	solver(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d ", sdoku[i][j]);
		printf("\n");
	}
	return 0;
}

//이함수는 스도쿠를 재귀형식으로 완성하는데 맨왼쪽위부터 맨 오른쪽아래까지차례로 검사하면서 맞으면 return 1을 틀리면 return 0을 리턴 한다.
int solver(int k)
{
	int x;
	int sub[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //후보숫자를 넣어둔 배열로 초기화 한다.
	int check = 0;

	if (k == 81) //k를 0부터 80까지 81개를 다 조사하고 k 81인 함수를 불렀으면 성공적으로 스도쿠를 완성한 것이므로 1를 리턴한다.
		return 1;

	if (sdoku[k / 9][k % 9] != 0)	//만약 이미 채워진 것을 reculsive 할때는 연결다리 역활만 하도록 한다.
		return solver(k + 1);

	//후보 숫자 조사
	for (x = 0; x< 9; x++)
	if (sdoku[k / 9][x] != 0)
		sub[sdoku[k / 9][x] - 1] = 0;
	for (x = 0; x< 9; x++)
	if (sdoku[x][k % 9] != 0)
		sub[sdoku[x][k % 9] - 1] = 0;

	for (x = 0; x < 9; x++)
	if (sdoku[k / 9 / 3 * 3 + x / 3][k % 9 / 3 * 3 + x % 3] != 0)
		sub[sdoku[k / 9 / 3 * 3 + x / 3][k % 9 / 3 * 3 + x % 3] - 1] = 0;

	//후보숫자가 몇개인지 확인
	for (x = 0; x< 9; x++)
		check += sub[x];

	if (check == 0)
		return 0;

	//후보숫자를 참고하여 넣어본다.
	for (x = 0; x<9; x++)
	if (sub[x] != 0){
		sdoku[k / 9][k % 9] = x + 1;

		if (solver(k + 1))
			return 1;
		else
			;
	}

	sdoku[k / 9][k % 9] = 0; //만약 아무것도 없어서 틀리면  초기화 시킨다.

	return 0; //틀렸기때문에 return 0를 한다.
}//solver

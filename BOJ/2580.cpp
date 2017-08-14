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

//���Լ��� ������ ����������� �ϼ��ϴµ� �ǿ��������� �� �����ʾƷ��������ʷ� �˻��ϸ鼭 ������ return 1�� Ʋ���� return 0�� ���� �Ѵ�.
int solver(int k)
{
	int x;
	int sub[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //�ĺ����ڸ� �־�� �迭�� �ʱ�ȭ �Ѵ�.
	int check = 0;

	if (k == 81) //k�� 0���� 80���� 81���� �� �����ϰ� k 81�� �Լ��� �ҷ����� ���������� ������ �ϼ��� ���̹Ƿ� 1�� �����Ѵ�.
		return 1;

	if (sdoku[k / 9][k % 9] != 0)	//���� �̹� ä���� ���� reculsive �Ҷ��� ����ٸ� ��Ȱ�� �ϵ��� �Ѵ�.
		return solver(k + 1);

	//�ĺ� ���� ����
	for (x = 0; x< 9; x++)
	if (sdoku[k / 9][x] != 0)
		sub[sdoku[k / 9][x] - 1] = 0;
	for (x = 0; x< 9; x++)
	if (sdoku[x][k % 9] != 0)
		sub[sdoku[x][k % 9] - 1] = 0;

	for (x = 0; x < 9; x++)
	if (sdoku[k / 9 / 3 * 3 + x / 3][k % 9 / 3 * 3 + x % 3] != 0)
		sub[sdoku[k / 9 / 3 * 3 + x / 3][k % 9 / 3 * 3 + x % 3] - 1] = 0;

	//�ĺ����ڰ� ����� Ȯ��
	for (x = 0; x< 9; x++)
		check += sub[x];

	if (check == 0)
		return 0;

	//�ĺ����ڸ� �����Ͽ� �־��.
	for (x = 0; x<9; x++)
	if (sub[x] != 0){
		sdoku[k / 9][k % 9] = x + 1;

		if (solver(k + 1))
			return 1;
		else
			;
	}

	sdoku[k / 9][k % 9] = 0; //���� �ƹ��͵� ��� Ʋ����  �ʱ�ȭ ��Ų��.

	return 0; //Ʋ�ȱ⶧���� return 0�� �Ѵ�.
}//solver

/*
왜1~i까지 몰아 넣는게 최대일까?
만약 s=1+2+3+...+i라면 s의 최대 N은 i이다. (trivial)
s가 이보다 1이라도 커지면 최대 N은 i일 수가 없다.(trivial)
만약 a < b라면 a의 최대 N은 b의 최대 N보다 작거나 같다.
a의 최대 N이 더 크다면 b = a+ b-a 이므로 a의 요소중 가장 큰값에 b-a 해주면 b의 최대 N은 적어도 a의 최대 N보단 크거나 같게 되므로 모순(귀류법)
따라서 1 + 2 +...+ i < s <= 1 + 2 + ... + (i + 1) 이라면 최대 N은 i+1일 것이다.
*/

#include <cstdio>

int main()
{
	long long s;

	scanf("%lld", &s);

	long long i = 0;

	while ((((i+1)*(i + 2)) >> 1) <= s)
		i++;
	printf("%lld\n", i);

	return 0;
}
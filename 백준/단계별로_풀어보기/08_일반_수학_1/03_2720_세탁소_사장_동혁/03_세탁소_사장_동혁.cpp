/*
날짜 : 2024. 8. 12
이름 : 배성훈
내용 : 세탁소 사장 동혁
	문제번호 : 2720번

	수학, 그리디, 사칙연산 문제다
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
#define endl	'\n'
using namespace std;

int main(void)
{

	int test, n;
	int a, b, c, d;
	FAST_IO;

	cin >> test;

	while (test--)
	{

		cin >> n;

		a = n / 25;
		n %= 25;

		b = n / 10;
		n %= 10;

		c = n / 5;
		n %= 5;

		d = n;

		cout << a << EMPTY << b << EMPTY << c << EMPTY << d << endl;
	}

	return 0;
}
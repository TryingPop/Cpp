/*
날짜 : 2024. 8. 1
이름 : 배성훈
내용 : A+B-3
	문제번호 : 10950번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>

#define endl '\n'
#define fastio cin.tie(0);		\
				cout.tie(0);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int test, a, b;
	fastio;

	cin >> test;
	while (test--)
	{

		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}
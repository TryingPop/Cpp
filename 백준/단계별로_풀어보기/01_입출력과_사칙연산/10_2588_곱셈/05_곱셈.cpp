/*
날짜 : 2024. 7. 28
이름 : 배성훈
내용 : 곱셈
	문제번호 : 2588번

	수학, 사칙연산 문제다
*/

#include <iostream>

#define endl '\n'

using namespace std;

int main(void)
{

	int a, b;
	cin >> a >> b;

	int c = b;
	while (c)
	{

		cout << a * (c % 10) << endl;
		c /= 10;
	}

	cout << a * b;
	return 0;
}
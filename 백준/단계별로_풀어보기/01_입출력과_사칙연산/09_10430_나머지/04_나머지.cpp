/*
날짜 : 2024. 7. 28
이름 : 배성훈
내용 : 나머지
	문제번호 : 10430번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>

#define endl '\n'

using namespace std;

int main(void)
{

	int a, b, c;

	cin >> a >> b >> c;

	cout << (a + b) % c << endl;
	cout << (a % c + b % c) % c << endl;
	cout << (a * b) % c << endl;
	cout << ((a % c) * (b % c)) % c;

	return 0;
}
/*
날짜 : 2024. 7. 30
이름 : 배성훈
내용 : 윤년
	문제번호 : 2753번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>

using namespace std;

inline bool IsLeapYear(int _year)
{

	if (_year % 400 == 0
		|| (_year % 100 && _year % 4 == 0)) return true;

	return false;
}

int main(void)
{

	int year;
	cin >> year;

	cout << IsLeapYear(year) ? '1' : '0';
	return 0;
}
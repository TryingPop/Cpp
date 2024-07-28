/*
날짜 : 2024. 7. 28
이름 : 배성훈
내용 : 1998년생인 내가 태국에서는 2541년생?!
	문제번호 : 18108번

	수학, 사칙연산 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	const int d = 2541 - 1998;

	int input;
	cin >> input;

	cout << input - d;
	return 0;
}
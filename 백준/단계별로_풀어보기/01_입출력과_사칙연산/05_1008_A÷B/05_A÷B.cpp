/*
날짜 : 2024. 7. 27
이름 : 배성훈
내용 : A/B
	문제번호 : 1008번

	수학, 구현, 사칙연산 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b;

	cin >> a >> b;

	// 10자리까지 표현
	cout.precision(10);

	cout << a / (double)b;

	return 0;
}
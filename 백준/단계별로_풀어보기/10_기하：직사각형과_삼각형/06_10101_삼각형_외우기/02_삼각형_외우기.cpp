/*
날짜 : 2024. 8. 17
이름 : 배성훈
내용 : 삼각형 외우기
	문제번호 : 10101번

	구현, 기하학 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b, c;
	cin >> a >> b >> c;

	if (a + b + c != 180) cout << "Error";
	else if (a == b && b == c) cout << "Equilateral";
	else if (a == b || b == c || c == a) cout << "Isosceles";
	else cout << "Scalene";

	return 0;
}
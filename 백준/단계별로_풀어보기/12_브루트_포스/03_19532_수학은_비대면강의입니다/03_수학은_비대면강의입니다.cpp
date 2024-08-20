/*
날짜 : 2024. 8. 20
이름 : 배성훈
내용 : 수학은 비대면강의입니다
	문제번호 : 19532번

	수학, 브루트포스 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;

	y = (c * d - a * f) / (b * d - a * e);
	x = (c * e - b * f) / (a * e - b * d);

	cout << x << ' ' << y;

	return 0;
}
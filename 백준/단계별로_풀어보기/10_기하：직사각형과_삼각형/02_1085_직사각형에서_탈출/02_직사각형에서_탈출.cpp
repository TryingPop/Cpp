/*
날짜 : 2024. 8. 16
이름 : 배성훈
내용 : 직사각형에서 탈출
	문제번호 : 1085번

	수학, 기하학 문제다
*/

#include <iostream>

#define min(X, Y)	(((X) < (Y)) ? (X) : (Y))
#define abs(X)		(((X) < 0) ? -(X) : (X))
using namespace std;

int main(void)
{

	int w, h, x, y;
	cin >> x >> y >> w >> h;
	cout << min(min(x, abs(w - x)), min(y, abs(h - y)));
}
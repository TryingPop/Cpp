/*
날짜 : 2024. 8. 16
이름 : 배성훈
내용 : 네 번째 점
	문제번호 : 3009번

	구현, 기하학 문제다
*/

#include <iostream>

#define EMPTY ' '
using namespace std;

int main(void)
{

	int x1, y1, x2, y2, x3, y3, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	if (x1 == x2) x = x3;
	else if (x2 == x3) x = x1;
	else x = x2;

	if (y1 == y2) y = y3;
	else if (y2 == y3) y = y1;
	else y = y2;

	cout << x << EMPTY << y;
	return 0;
}
/*
날짜 : 2024. 8. 17
이름 : 배성훈
내용 : 세 막대
	문제번호 : 14215번

	수학, 구현, 기하학 문제다
*/

#include <iostream>

#define min(a, b)	(((a) < (b)) ? (a) : (b))
using namespace std;

int main(void)
{

	int a, b, c;
	cin >> a >> b >> c;

	if (b <= a && c <= a) a = min(a, b + c - 1);
	else if (a <= b && c <= b) b = min(b, a + c - 1);
	else c = min(c, a + b - 1);

	cout << a + b + c;
	return 0;
}
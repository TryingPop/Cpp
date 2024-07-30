/*
날짜 : 2024. 7. 30
이름 : 배성훈
내용 : 두 수 비교하기
	문제번호 : 1330번

	구현 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b;
	cin >> a >> b;

	if (a < b) cout << '<';
	else if (a == b) cout << '=' << '=';
	else cout << '>';

	return 0;
}
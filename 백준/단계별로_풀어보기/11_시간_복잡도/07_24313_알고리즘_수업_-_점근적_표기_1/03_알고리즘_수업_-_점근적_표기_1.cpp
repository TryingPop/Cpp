/*
날짜 : 2024. 8. 19
이름 : 배성훈
내용 : 알고리즘 수업 - 점근적 표기 1
	문제번호 : 24313번

	수학 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a1, a0, c, n0, ret;

	cin >> a1 >> a0 >> c >> n0;

	ret = a1 * n0 + a0 <= c * n0 && a1 <= c;
	cout << ret;
	return 0;
}
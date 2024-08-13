/*
날짜 : 2024. 8. 13
이름 : 배성훈
내용 : 분수찾기
	문제번호 : 1193번

	수학, 구현 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int n;
	cin >> n;

	int cnt = 1;
	bool isL = true;
	while (n > cnt)
	{

		n -= cnt++;
		isL = !isL;
	}

	cout << (isL ? (cnt + 1 - n) : n) << '/' << (isL ? n : (cnt + 1 - n));
	return 0;
}
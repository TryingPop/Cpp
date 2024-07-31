/*
날짜 : 2024. 7. 31
이름 : 배성훈
내용 : 오븐 시계
	문제번호 : 2525번

	수학, 사칙연산 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int h, m, temp;
	cin >> h >> m >> temp;

	int addH, addM;
	addH = temp / 60;
	addM = temp % 60;

	m += addM;
	if (60 <= m) 
	{

		m -= 60;
		h += 1;
	}

	h += addH;
	if (24 <= h) h %= 24;

	cout << h << ' ' << m;
	return 0;
}
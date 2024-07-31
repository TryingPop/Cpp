/*
날짜 : 2024. 7. 31
이름 : 배성훈
내용 : 알람 시계
	문제번호 : 2884번

	수학, 사칙연산 문제다
*/

#include <iostream>

using namespace std;

int main(void)
{

	int hour, minute;
	cin >> hour >> minute;

	minute -= 45;
	if (minute < 0)
	{

		minute += 60;
		hour -= 1;
		if (hour < 0) hour += 24;
	}
	
	cout << hour << ' ' << minute;
	return 0;
}
/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : Rectangle 클래스 정의
	교재 p156 ~ 157

	오류상황에 대한 처리의 방법은 
	프로그램의 성격 및 내용에 따라 달라질 수 있다
*/

#include <iostream>
#include "04_Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{

	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{

		cout << "잘못된 위치정보 전달" << endl;
		return false;
	}

	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const
{

	cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}
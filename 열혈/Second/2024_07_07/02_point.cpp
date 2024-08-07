/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : point 클래스 정의
	교재 p177 ~ 178
*/

#include <iostream>
#include "01_point.h"

using namespace std;

Point::Point(const int& xpos, const int& ypos)
{

	x = xpos;
	y = ypos;
}

int Point::GetX() const { return x; }
int Point::GetY() const { return y; }

bool Point::SetX(int xpos)
{

	if (0 > xpos || xpos > 100)
	{

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{

	if (0 > ypos || ypos > 100)
	{

		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	y = ypos;
	return true;
}
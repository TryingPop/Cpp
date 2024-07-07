/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : rectangle
	교재 p178
*/

#include <iostream>
#include "03_rectangle.h"

using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	:upLeft(x1, y1), lowRight(x2, y2)
{

	// Empty
}

void Rectangle::ShowRecInfo() const
{

	cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}
/*
날짜 : 2024. 7. 7
이름 : 배성훈
내용 : rectangle 헤더 파일
	교재 p178
*/

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "01_point.h"

class Rectangle
{

private:
	Point upLeft;
	Point lowRight;

public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	void ShowRecInfo() const;
};
#endif
/*
날짜 : 2024. 6. 25
이름 : 배성훈
내용 : Rectangle 헤더파일
	교재 p156
*/

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "02_Point.h"

class Rectangle
{

private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point& ul, const Point& lr);
	void ShowRecInfo() const;
};
#endif
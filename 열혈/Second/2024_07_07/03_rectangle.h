/*
��¥ : 2024. 7. 7
�̸� : �輺��
���� : rectangle ��� ����
	���� p178
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
/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : Rectangle �������
	���� p156
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
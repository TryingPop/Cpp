/*
��¥ : 2023. 1. 27
�̸� : �輺��
���� : ���� ������ �ʿ伺
	Rectangle Ŭ����

	������� : Ŭ���� ����
*/

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_
#include "02_����.h"

class Rectangle {

private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point& ul, const Point& lr);
	void ShowRecInfo() const;
};

#endif

/*
��¥ : 2023. 1. 28
�̸� : �輺��
���� : ������ ����
	Exam Ch03 01 �� 01 ���������� ����

	������� : Ŭ���� ����
*/

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "04_Point.h"

class Rectangle {

private:
	Point upLeft;
	Point lowRight;

public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	void ShowRecInfo() const;
};
#endif
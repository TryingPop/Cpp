/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : �迭 Ŭ������ ���ø�ȭ
	�ڵ����� : Point Ŭ������ ����
*/

#include <iostream>
#include "07_Point.h"

using namespace std;

Point::Point(int x, int y)
	: xpos(x), ypos(y) { }

ostream& operator<<(ostream& os, const Point& pos) {

	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
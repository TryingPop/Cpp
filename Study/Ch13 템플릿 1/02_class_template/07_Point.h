/*
��¥ : 2023. 2. 23
�̸� : �輺��
���� : �迭 Ŭ������ ���ø�ȭ
	������� : Point Ŭ������ ����
*/

#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

class Point {

private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0);
	friend ostream& operator<<(ostream& os, const Point& pos);
};

#endif
/*
��¥ : 2023. 1. 28
�̸� : �輺��
���� : ������ ����
	Exam Ch03 01 �� 01 ���������� ����

	�ҽ����� : Ŭ���� ����
*/

#include <iostream>
#include "06_Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2) : upLeft(x1, y1), lowRight(x2, y2) {

	// empty
}

void Rectangle::ShowRecInfo() const {

	cout << "�� ���: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}
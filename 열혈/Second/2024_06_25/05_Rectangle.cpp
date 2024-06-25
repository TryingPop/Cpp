/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : Rectangle Ŭ���� ����
	���� p156 ~ 157

	������Ȳ�� ���� ó���� ����� 
	���α׷��� ���� �� ���뿡 ���� �޶��� �� �ִ�
*/

#include <iostream>
#include "04_Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{

	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{

		cout << "�߸��� ��ġ���� ����" << endl;
		return false;
	}

	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const
{

	cout << "�� ���: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}
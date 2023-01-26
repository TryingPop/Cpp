/*
��¥ : 2023. 1. 27
�̸� : �輺��
���� : ���� ������ �ʿ伺
	Point Ŭ����

	�ҽ����� : �Լ��� ����

	��������� private���� �����ϰ�, 
	�ش� ������ �����ϴ� �Լ��� ������ �����ؼ�,
	������ ���·� ��������� ������ �����ϴ� ���� �ٷ� '��������'�̸�,
	�̴� ���� Ŭ������ �Ǳ� ���� �⺻������ �ȴ�.
*/

#include <iostream>
#include "02_����.h"
using namespace std;

bool Point::InitMembers(int xpos, int ypos) {

	if (xpos < 0 || ypos < 0 || xpos > 100 || ypos > 100) {

		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const {	// const �Լ�
							// ��������� ����� ���� �������� �ʰڴٴ� �ǹ�
							// const�Լ��� const �Լ��� ȣ�� ����
							// ������ ���� ��������

	return x;
}

int Point::GetY() const {

	return y;
}

bool Point::SetX(int xpos) {

	if (0 > xpos || xpos > 100) {

		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos) {

	if (0 > ypos || ypos > 100) {

		cout << "��� ������ �� ����" << endl;
		return false;
	}

	y = ypos;
	return true;
}
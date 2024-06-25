/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : Point �ҽ�����
	���� p154 ~ 155

	��������� private�� �����ϰ�, �ش� ������ �����ϴ� �Լ��� ������ �����ؼ�,
	������ ���·� ��������� ������ �����ϴ� ���� �ٷ� ���������̸�
	�̴� ���� Ŭ������ �Ǳ� ���� �⺻������ �ȴ�

	�Ʒ� ��������
	GetX, SetX, GetY, SetY�� ������ �Լ�(accesss function)�� �ϴµ�,
	�̵��� ��� ������ private�� �����ϸ鼭
	Ŭ���� �ܺο��� ������� ������ �������� ���ǵǴ� �Լ����̴�

	Ŭ������ ������ �� ȣ��� �Լ��� ���ַ� ����Լ��� �����ϴ� ���� �и� �´�
	�׷��� Ŭ������ ���ǰ������� ������ �ʿ����� ������,
	�ʿ��� �� �ִٰ� �ǴܵǴ� �Լ��鵵 ���Ҿ� ����� ���Խ�Ű�� ��쵵 ����
	��ǥ���� ���� ������ �Լ����̴�
	ȣ����� ������ ���Ե� �Լ��� �ִٸ�, �̷��� �ƶ����� �����ϸ� ����
*/

#include <iostream>
#include "02_Point.h"

using namespace std;

bool Point::InitMembers(int xpos, int ypos)
{

	if (xpos < 0 || ypos < 0) 
	{

		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const	// const �Լ�
{

	return x;
}

int Point::GetY() const	// const �Լ�
{

	return y;
}

bool Point::SetX(int xpos)
{

	if (0 > xpos || xpos > 100)
	{

		cout << "��� ������ �� ����" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{

	if (0 > ypos || ypos > 100)
	{

		cout << "��� ������ �� ����" << endl;
		return false;
	}

	y = ypos;
	return true;
}
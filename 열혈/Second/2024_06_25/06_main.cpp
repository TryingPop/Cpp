/*
��¥ : 2024. 6. 25
�̸� : �輺��
���� : main �Լ�
	���� p157 ~ 158

	�ʱ�ȭ�� ���� ���ο� ���� true �Ǵ� false�� ��ȯ�ϵ��� �����߱� ������,
	�Լ��� ȣ���� �������� �������θ� Ȯ���ϰ� �׿� ���� ��ġ�� ���� �� �ִ�

	��ǥ������ ���α׷� ����ڷκ��� �Է� �޴� �������ٸ�, 
	�������� ��ǥ�� �Է��� �� ��û�� ���� �ִ�
*/

#include <iostream>
#include "02_Point.h"
#include "04_Rectangle.h"

using namespace std;

int main(void)
{

	Point pos1;

	// ��� ������ �� ����
	// �ʱ�ȭ ����
	if (!pos1.InitMembers(-2, 4)) cout << "�ʱ�ȭ ����" << endl;

	if (!pos1.InitMembers(2, 4)) cout << "�ʱ�ȭ ����" << endl;

	Point pos2;
	if (!pos2.InitMembers(5, 9)) cout << "�ʱ�ȭ ����" << endl;

	Rectangle rec;

	// �߸��� ��ġ���� ����
	// ���簢�� �ʱ�ȭ ����
	if (!rec.InitMembers(pos2, pos1)) cout << "���簢�� �ʱ�ȭ ����" << endl;

	if (!rec.InitMembers(pos1, pos2)) cout << "���簢�� �ʱ�ȭ ����" << endl;

	//
	// �� ���: [2, 4]
	// �� �ϴ�: [5, 9]
	rec.ShowRecInfo();
	return 0;
}
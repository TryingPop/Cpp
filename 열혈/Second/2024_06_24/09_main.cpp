/*
��¥ : 2024. 6. 24
�̸� : �輺��
���� : main
	���� p134

	�����Ϸ��� ���� ������ ������ �Ѵ�!
	A.cpp�� B.cpp�� ���ÿ� �������ؼ� �ϳ��� ���������� ����� �ص�,
	A.cpp�� ������ �������� B.cpp�� �������� ������
	B.cpp�� ������ �������� A.cpp�� �������� �ʴ´�
*/

#include "07_CarInline.h"

int main(void)
{

	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	return 0;
}
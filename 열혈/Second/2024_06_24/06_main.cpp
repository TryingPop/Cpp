/*
��¥ : 2024. 6. 24
�̸� : �輺��
���� : main
	���� p130 ~ 131

	������ �����ϸ� Ŭ������ �����ϴ� ����� �ľǵ� �Ѱ� ����������
	�׸��� ���� ������ ������ ���

	������ ������ ����ϴٺ��� ������ �ڿ������� �˰� �ȴ�
*/

#include "04_Car.h"

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
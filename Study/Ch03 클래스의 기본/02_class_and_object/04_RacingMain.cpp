/*
��¥ : 2023. 1. 25
�̸� : �輺��
���� : RacingCar class�� ����
	�ҽ����� : �����Լ� ����
*/

#include "02_Car.h"

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
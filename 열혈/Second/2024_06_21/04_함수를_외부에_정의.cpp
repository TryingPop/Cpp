/*
��¥ : 2024. 6. 21
�̸� : �輺��
���� : �Լ��� �ܺο� ����
	���� p118 ~ 121

	�Լ��� ���ԵǾ� �ִ� C++�� ����ü�� ���� ����
	����Ǿ� �ִ� ��������, ���ǵǾ� �ִ� �Լ�����
	�� ���� ���� ���;� �ڵ��� �м��� �����ϴ�

	���α׷��� �м��� ��, �帧 �� ��� ���ַ� �м��ϴ� ��찡 ����
	�׸��� �̷��� ��쿡�� �Լ��� ��ɸ� �ľ��� ����
	�Լ��� ���α��������� �Ű��� ���� �ʴ´�

	���� ���ǵǾ� �ִ� �Լ��� ������ ����� �Ѵ��� �����Բ� �ڵ带 �ۼ��ϴ� ���� ����
	���� ����ü ���� ���ǵǾ� �ִ� �Լ��� ���� ���ų� �� ���̰� ��ٸ�,
	����ü ������ �Լ��� ���� �ʿ䰡 �ִ�

	��, �Լ��� ���������� ����ü �ȿ� �ΰ�, 
	�Լ��� ���Ǹ� ����ü ������ ������ ���̴�

	�ٸ� ���� ������ �ش� �Լ��� ��� ���ǵǾ� �ִ����� ���� ������ �߰����ָ� �ȴ�
	�׸��� ����ü �ȿ� �Լ��� ���ǵǾ� ������ �Լ��� �ζ������� ó���ض�� �ǹ̰� ���Ҿ� �����ȴ�

	�ݸ�, �Ʒ� ����ó�� �Լ��� ����ü ������ ������ �̷��� �ǹ̰� �������
	���� �ζ����� �ǹ̸� �״�� �����Ϸ��� inline Ű���带 �̿��ؼ� �ζ��� ó���� ��������� �����ؾ��Ѵ�
*/

#include <iostream>

using namespace std;

namespace CAR_CONST 
{

	enum
	{

		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car
{

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();	// �������� ���
	void Accel();			// ����, �ӵ�����
	void Break();			// �극��ũ, �ӵ�����
	// inline void ShowCarState();
};

void Car::ShowCarState() 
{

	cout << "������ ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() 
{

	if (fuelGauge <= 0) return;
	else fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{

		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() 
{

	if (curSpeed < CAR_CONST::BRK_STEP)
	{

		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{

	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}
/*
��¥ : 2024. 6. 24
�̸� : �輺��
���� : �������� ������(�������� ���̺�)
	���� p122 ~ 126

	C++���� �������� �����ڴ� �� 3������ �����Ѵ�
		public, protectd, private

	�̵��� �ǹ��ϴ� �ٴ�
	public ��𼭵� �������
	protected ��Ӱ��迡 �������� ��, ���� Ŭ���������� ���� ���
	private Ŭ���� ��(Ŭ���� ���� ���ǵ� �Լ�)������ ���� ���

	protected�� ��Ӱ� ������ �����Ƿ� ���߿� ���캸��,
	public�� private���� ����

	�������� �����ڰ� ����Ǹ�,
	�� ���Ŀ� �����ϴ� ������ �Լ��� A�� �ش��ϴ� ���� ������ ������ �����ϴ�

	�׷��� ���ο� �������� ������ B�� ����Ǹ�,
	�� ���ķ� �����ϴ� ������ �Լ��� B�� �ش��ϴ� ���� ������ ������ �����ϴ�

	�Լ��� ���Ǹ� Ŭ���� ������ ����,
	�̴� Ŭ������ �Ϻ��̱� ������,
	�Լ� �������� private�� ����� ������ ������ �����ϴ�

	Ű���� struct�� �̿��ؼ� ������ ����ü��
	����� ������ �Լ��� ������ �������� �����ڸ� �������� ������
	��� ������ �Լ��� public���� ����ȴ�
	(struct�� �������� �����ڸ� ������ �� �ִ�)

	Ű���� class�� �̿��ؼ� ������ Ŭ������ ����� ������ �Լ���
	������ �������� �����ڸ� �������� ������,
	��� ������ �Լ��� private�� ����ȴ�
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

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

class Car 
{

private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel) 
{

	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState() 
{

	cout << "������ ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl;
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
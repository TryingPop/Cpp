/*
��¥ : 2023. 2. 25
�̸� : �輺��
���� : dynamic_cast
	��Ӱ��迡���� ������ ����ȯ

	dynamic_cast<T>(expr)
		<> ���̿� ��ȯ�ϰ��� �ϴ� �ڷ����� �̸��� �ΰ� ��ü�� ������ �Ǵ� �������� �;��Ѵ�
		() ���̿��� ��ȯ�� ����̿;� �Ѵ�
		�׸��� �䱸�� �� ��ȯ�� ������ ��쿡�� �� ��ȯ�� �����͸� ��ȯ������
		�䱸�� �� ��ȯ�� �������� �ʴ� ��쿡�� ������ ������ �߻�

		�������� �ʴ� ����
			��Ӱ��迡 ���� �ִ� �� Ŭ���� ���̿��� ���� Ŭ������ ������ �� ������ �����͸�
			���� Ŭ������ ������ �� ������ �����ͷ� �� ��ȯ�ϴ� ���
*/

#include<iostream>
using namespace std;

class Car {

private:
	int fuelGauge;

public:
	Car(int fuel)
		: fuelGauge(fuel) { }

	void ShowCarState() const {

		cout << "�ܿ� ���ᷮ: " << fuelGauge << endl;
	}
};

class Truck : public Car{

private:
	int freightWeight;

public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight) { }

	void ShowTruckState() {

		cout << "ȭ���� ����: " << freightWeight << endl;
	}
};

int main(void)
{

	Car* pcar1 = new Truck(80, 120);
	// Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);	// ������ ����

	Car* pcar2 = new Car(120);
	// Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);	// ������ ����

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);
	return 0;
	return 0;
}
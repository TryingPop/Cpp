/*
��¥ : 2023. 2. 25
�̸� : �輺��
���� : static_cast
	dynamic_cast �����ڿ� ������ �����̴�
	static_cast<T>(expr)

	dynamic_cast �����ڸ� ����� �� �ִ� ��쿡�� dynamic_cast �����ڸ� �̿��� �������� �������ϰ�
	�� �̿��� ��쿡�� ���� å���� �� �ִ� ��Ȳ���� static_cast �����ڸ� �̿��ؾ��Ѵ�

	static_cast�� dynamic_cast���� �ӵ��� ������

	static_cast �����ڴ� �⺻ �ڷ��� ���� �� ��ȯ�� Ŭ������ ��Ӱ��迡���� �� ��ȯ���� ����Ѵ�
	�ݸ� C����� �� ��ȯ �����ڴ� ���� �ȵǴ� �� ��ȯ�� ����ϹǷ� static_cast �����ڸ� �̿��ϴ� ���� ����
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

class Truck : public Car {

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
	Truck* ptruck1 = static_cast<Truck*>(pcar1);		

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);	// ������ ok 
													// �׷��� �ǵ����� ���� ��Ȳ�� ���α׷��Ӱ� å�������Ѵ�

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);
	return 0;
	return 0;
}
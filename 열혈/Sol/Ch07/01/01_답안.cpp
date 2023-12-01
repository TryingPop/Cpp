/*
��¥ : 2023. 2. 7
�̸� : �輺��
���� : ���� 294p ����1
	�ռ� ��Ӱ��迡 �����ִ� Ŭ������ ������ ���� �� ȣ�� ��Ŀ� ���� �����Ͽ���.
	�� ������ �������� ���� Ŭ������ ������ �����ڸ� �����غ���. �׸��� ���� Ȯ���� ���� main �Լ��� ������ �����غ���.
	class Car {	// �⺻ ���� �ڵ���

	private:
		int gasolineGauge;
	public:
		int GetGasGauge() {
			return gasolineGauge;
		}
	};
	class HybridCar : public Car {	// ���̺긮�� �ڵ���
	private:
		int electricGauge;
	public:
		int GetElecGauge() {

			return electricGauge;
		}
	};
	class HybridWaterCar : public HybridCar	{	// ���̺긮�� ����ī
	private:
		int waterGauge;
	public:
		void ShowCurrentGauge() {
			cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
			cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
			cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
		}
	};
	�����, Car Ŭ������ ���ָ����� �����ϴ� �ڵ����� ǥ���� ���̰�,
	HybridCar Ŭ������ ���ָ��� ����� �����ϴ� �ڵ����� ǥ���� ���̴�.
	�׸��� ���������� HybridWaterCar Ŭ������ ���ָ��� ����Ӹ� �ƴ϶�,
	���� ���ÿ� ����� ����� �� �ִ�, ������ �ڵ����� ǥ���� ���̴�.
	�׷��� �� ������ ���� Ŭ�������� �ǹ��ϴ� �ٸ� ���� �ذ��� �����ϴ�.

	�׸��� ���� �ڵ忡���� �ռ� ���� ������� �޸� ����� ����(�� �ܰ迡 ���ļ� ����� �̷����� �ִ°��� �ǹ���)�� �� �ܰ� ����������,
	�׷� ���ؼ� �������� �� �˾ƾ� �� ������ ������ �ְų�, �ؼ��ϴ� ��Ŀ� �־ ���̰� �ִ� ���� �ƴϴ�
*/

#include <iostream>
using namespace std;

class Car {	// �⺻ ���� �ڵ���

private:
	int gasolineGauge;

public:
	Car(int gas)
		: gasolineGauge(gas) { }

	int GetGasGauge() {

		return gasolineGauge;
	}
};

class HybridCar : public Car {	// ���̺긮�� �ڵ���

private:
	int electricGauge;

public:
	HybridCar(int gas, int elec)
		: Car(gas), electricGauge(elec) { }

	int GetElecGauge() {

		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {	// ���̺긮�� ����ī

private:
	int waterGauge;

public:
	HybridWaterCar(int gas, int elec, int water)
		: HybridCar(gas, elec), waterGauge(water) { }

	void ShowCurrentGauge() {

		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int main(void) 
{

	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}
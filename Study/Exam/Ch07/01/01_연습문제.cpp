/*
��¥ : 2023. 2. 6
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

#include <iostream>		// cout 
using namespace std;

class Car {

private:
	int gasolineGauge;

public:
	Car() {

		cout << "Car() : " << gasolineGauge << endl;
	}

	Car(int gasGauge)
		: gasolineGauge(gasGauge) { 
	
		cout << "Car(int) : " << gasolineGauge << endl;
	}

	int GetGasGauge() {

		return gasolineGauge;
	}
};

class HybridCar : public Car {

private:
	int electricGauge;

public:
	HybridCar() {

		cout << "HybridCar() : " << electricGauge << endl;
	}
	HybridCar(int gasGauge, int elecGauge)
		: Car(gasGauge), electricGauge(elecGauge) { 
	
		cout << "HybridCar(int, int) : " << electricGauge << endl;
	}

	int GetElecGauge() {

		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {

private:
	int waterGauge;

public:
	HybridWaterCar() { 
	
		cout << "HybridWaterCar() : " << waterGauge << endl;
	}

	HybridWaterCar(int gasGauge, int elecGauge, int waterGauge)
		: HybridCar(gasGauge, elecGauge), waterGauge(waterGauge) {
	
		cout << "HybridWaterCar(int, int, int) : " << waterGauge << endl;
	}

	void ShowCurrentGauge() {

		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};


int main(void) 
{

	HybridWaterCar hwc1;			// Car, HybridCar, HybridWaterCar ������ ȣ��ȴ�
									// gauge ���� �����Ⱚ�� ���´�
	cout << "------------------------" << endl;
	HybridWaterCar hwc2(1, 2, 3);	// Car, HybridCar, HybridWaterCar ������ ȣ��ȴ�

	return 0;
}
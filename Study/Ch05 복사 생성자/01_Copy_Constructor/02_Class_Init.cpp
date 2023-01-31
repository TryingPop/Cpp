/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���������
	Ŭ������ ������ = ���� Ÿ���� ������
	���� �����ϸ�
	Ŭ������ ������(���� Ÿ���� ������) ���·� �д´�
*/

#include <iostream>
using namespace std;

class SoSimple {

private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) {
	}

	SoSimple(SoSimple& copy) 
		: num1(copy.num1), num2(copy.num2) {
	}

	void ShowSimpleData() {

		cout << num1 << endl;
		cout << num2 << endl;
	}

	void ShowSimpleAddr() {

		cout << &num1 << endl;
		cout << &num2 << endl;
	}
};

int main(void)
{

	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1;	// SoSimple sim2(sim1)���� ��ȯ�ȴ�
	cout << "���� �� �ʱ�ȭ ����" << endl;

	sim2.ShowSimpleData();

	// 
	cout << "sim1" << endl;
	cout << &sim1 << endl;
	sim1.ShowSimpleAddr();
	cout << "sim2" << endl;
	cout << &sim2 << endl;
	sim2.ShowSimpleAddr();
	return 0;
}
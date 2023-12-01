/*
��¥ : 2023. 1. 31
�̸� : �輺��
���� : ���������
	C++���� �ʱ�ȭ�ϴ� ���
	���� ��ü�� �̿��� ���ο� ��ü ����
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

	void ShowSimpleData() {

		cout << num1 << endl;
		cout << num2 << endl;
	}

	void ShowSimpleAddr() {

		cout << "num1 : " << &num1 << endl;
		cout << "num2 : " << &num2 << endl;
	}
};

int main(void)
{
	
	int val1(20);
	int val2 = 20;

	SoSimple sim1(15, 20);
	SoSimple sim2 = sim1;
	
	sim2.ShowSimpleData();		// ���� ����

	// �׷��� �������� �ּҰ� �ٸ���
	// �� �����ʹ� ����
	cout << "sim1 : " << endl;
	cout << &sim1 << endl;
	sim1.ShowSimpleAddr();
	
	cout << "sim2 : " << endl;
	cout << &sim2 << endl;
	sim2.ShowSimpleAddr();


	return 0;
}
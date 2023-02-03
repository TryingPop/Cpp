/*
��¥ : 2023. 2. 3
�̸� : �輺��
���� : mutable Ű����
	const�� explicit Ű����� ���� �ǹ̰� ������, �� �����ϰ� ���Ǵ� Ű����
	�ݸ� mutable�� ������ ����� �󵵼��� ����� �ϴ� Ű����

	const �Լ� �������� ���� ������ ���������� ����ϴ� Ű����
*/

#include <iostream>
using namespace std;

class SoSimple {
	
private:
	int num1;
	mutable int num2;	// const �Լ��� ���� ���ܸ� �д�

public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2) { }

	void ShowSimpleData() const {

		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() {

		num2 = num1;
		// mutable�� num1 = num2�� �����Ѵٴ� �鿡���� ���� �� �ִ�
	}
};

int main(void)
{

	SoSimple sm(1, 2);
	sm.ShowSimpleData();	// 1, 2
	sm.CopyToNum2();
	sm.ShowSimpleData();	// 1, 1
	return 0;
}
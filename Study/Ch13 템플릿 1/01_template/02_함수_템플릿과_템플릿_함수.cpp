/*
��¥ : 2023. 2. 22
�̸� : �輺��
���� : �Լ� ���ø��� ���ø� �Լ��� ����
	�Լ��� ���ø�
		�Լ��� ����� �����̴�
		�Լ��� ����� �����Ǿ��� ������, �ڷ����� �����Ǿ� ���� �ʾ� �پ��� �ڷ����� �Լ��� ���� �� �ִ�

	���ø� �Լ�
		���ø��� ������� �����Ϸ��� ����� ���� �Լ�
*/

#include <iostream>
using namespace std;

// �Լ��� ���ø�
template <typename T>
T Add(T num1, T num2) {

	return num1 + num2;
}

int main(void)
{

	cout << Add<int>(15, 20) << endl;			// ���ø� �Լ� Add(int num1, int num2) ����
	cout << Add<double>(3.7, 7.5) << endl;		// ���ø� �Լ� Add(double num1, double num2) ����
	cout << Add<int>(3.2, 3.2) << endl;			// ���ø� �Լ� Add(int num1, int num2) �Լ� ȣ��
	cout << Add<double>(3.14, 2.75) << endl;	// ���ø� �Լ� Add(double num1, double num2) �Լ� ȣ��

	cout << Add(15, 20) << endl;				// ���ø� �Լ� Add(int num1, int num2) �Լ� ȣ��
	cout << Add(3.7, 7.5) << endl;				// ���ø� �Լ� Add(double num1, double num2) �Լ� ȣ��
	cout << Add(3.2, 3.2) << endl;				// ���ø� �Լ� Add(double num1, double num2) �Լ� ȣ��
	cout << Add(3.14, 2.75) << endl;			// ���ø� �Լ� Add(double num1, double num2) �Լ� ȣ��
	return 0;
}
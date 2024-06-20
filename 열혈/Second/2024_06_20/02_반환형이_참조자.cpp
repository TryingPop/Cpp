/*
��¥ : 2024. 6. 20
�̸� : �輺��
���� : ��ȯ���� ������(Reference Type)�� ���
	���� p82 ~ 86

	�Լ��� ��ȯ������ �������� ����� �� �ִ�
	��ȯ ���� �������� ���
	�ݵ�� ������ �����ؾ��ϰ�, �ش� ��ȯ���� ����� �ٸ����� ������
	������ �������� �ش� ���� ���� �� ����
*/

#include <iostream>

using namespace std;

int& RefRetFuncOne(int& _ref)
{

	_ref++;
	return _ref;
}

int RefRetFuncTwo(int& _ref)
{

	_ref++;
	return _ref;
}

int main(void)
{

	int num1 = 1;
	int num2 = RefRetFuncOne(num1);
	int& ref2 = RefRetFuncOne(num1);
	RefRetFuncOne(num1);

	int num3 = RefRetFuncTwo(num1);
	// int& ref3 = RefRetFuncTwo(num1);	// ������ ����
	RefRetFuncTwo(num1);

	num1 += 10;
	num2 += 100;
	num3 += 1000;

	cout << "num1: " << num1 << endl;	// 16
	cout << "num2: " << num2 << endl;	// 102
	cout << "num3: " << num3 << endl;	// 1005

	return 0;
}
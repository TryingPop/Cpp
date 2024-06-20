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

	int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5;
	int ref1 = RefRetFuncOne(num1);
	int& ref2 = RefRetFuncOne(num2);	// num2�� �����Ѵ�!
	RefRetFuncOne(num5);

	int ref3 = RefRetFuncTwo(num3);
	// int& ref4 = RefRetFuncTwo(num4);	// ��ȯ ���� ����� ���¶� ������ ����
	RefRetFuncTwo(num5);

	ref1 += 10;
	ref2 += 20;
	ref3 += 30;

	cout << "ref1: " << ref1 << endl;	// 12
	cout << "ref2: " << ref2 << endl;	// 23
	cout << "ref3: " << ref3 << endl;	// 34

	cout << "num1: " << num1 << endl;	// 2
	cout << "num2: " << num2 << endl;	// 23
	cout << "num3: " << num3 << endl;	// 4
	cout << "num4: " << num4 << endl;	// 4
	cout << "num5: " << num5 << endl;	// 7
	return 0;
}
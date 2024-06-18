/*
��¥ : 2024 .6. 18
�̸� : �輺��
���� : C����� ���� (const Ű����)
	���� p62 ~ 63

	���� Ű���� const�� �ǹ̸� ����
		cont int num = 10;
		cont int* ptr1 = &val1;
		int* const ptr2 = &val2;
		const int* const ptr3 = &val3;

	�� �������� ����

	const int num = 10�� ���
	num �� ��� ����Ѵٴ� �ǹ��̴�
	�̴� num�� ���� ������ �� ����

	const int* ptr1�� ptr1�� ����Ű�� ����� ���� �������ؼ� ptr1���δ� ������ �� ����
	������ ptr1 ����Ű�� ����� �ٲ� �� �ִ�
	ptr1���θ� ����Ű�� ���� ���� ���� ��!�̴�!

	int* const ptr2�� ptr2�� ����Ű�� ����� ��� ����ؼ� ptr2�� ����� ������ ������
	������ ptr2�� ����Ű�� ����� �ٲ� �� �ִ�

	const int* const ptr3�� ptr3�� ����Ű�� ����� ������ �� ����
	�׸��� ptr3�� ����Ű�� ����� ptr3�δ� �ٲ� �� ����
*/

#include <iostream>

#define endl '\n'
using namespace std;

int main(void)
{

	int num1 = 10, num2 = 100;
	
	const int* ptr1 = &num1;
	ptr1 = &num2;
	// *ptr1 = 30;				// ������ ����
	cout << "ptr1: " << *ptr1 << endl;
	num1 = 50;					// ptr1�θ� ���� ���� ���̴�!

	int* const ptr2 = &num1;
	// ptr2 = &num2;			// ������ ����
	*ptr2 = 20;

	cout << "ptr2: " << *ptr2 << endl;

	const int* const ptr3 = &num1;
	// ptr3 = &num2;
	// *ptr3 = 30;
	cout << "ptr3: " << *ptr3 << endl;
}
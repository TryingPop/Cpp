/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : ���� 80p ����3
	������ ���ÿ� �ռ� ���� ���� �ڵ带 ����
	int main(void)
	{
		int num1 = 5;
		int* ptr1 = &num1;
		int num2 = 10;
		int* ptr2 = &num2;
		...
	}

	���� �ڵ带 ���� ptr1�� ptr2�� ���� num1�� num2�� ����Ű�� �ִ�.
	�� �� ptr1�� ptr2�� ������� ������ ���� �Լ��� ȣ���ϰ� ����,
		SwapPointer(ptr1, ptr2);
	ptr1�� ptr2�� ����Ű�� ����� ���� �ٲ�� SwapPointer �Լ��� �����غ���.
*/
#include<iostream>
using namespace std;


void SwapPointer(int* (&ptr1), int* (&ptr2)) {

	int* temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

// �ٲ���� Ȯ�ο�
int main(void)
{

	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	cout << "Before ptr1 : " << ptr1 << endl;
	cout << "Before ptr2 : " << ptr2 << endl;

	SwapPointer(ptr1, ptr2);

	cout << "After ptr1 : " << ptr1 << endl;
	cout << "After ptr2 : " << ptr2 << endl;
}

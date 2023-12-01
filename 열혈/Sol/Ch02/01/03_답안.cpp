/*
��¥ : 2023. 1. 25
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

#include <iostream>
using namespace std;

void SwapPointer(int* (&pref1), int* (&pref2)) {

	int* ptr = pref1;
	pref1 = pref2;
	pref2 = ptr;
}

int main(void) 
{

	int num1 = 5;
	int* ptr1 = &num1;

	int num2 = 10;
	int* ptr2 = &num2;

	cout << *ptr1 << endl;	// 5
	cout << *ptr2 << endl;	// 10

	SwapPointer(ptr1, ptr2);

	cout << *ptr1 << endl;	// 10
	cout << *ptr2 << endl;	// 5
	return 0;
}
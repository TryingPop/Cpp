/*
��¥ : 2023. 1. 23
�̸� : �輺��
���� : ������
	�迭�� �����͸� �����ϴ� ����
*/

#include <iostream>
using namespace std;

int main(void)
{

	// �迭 �����ϴ� ����
	int arr[3] = { 1, 3, 5 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << "ref1 : " << ref1 << endl;
	cout << "ref2 : " << ref2 << endl;
	cout << "ref3 : " << ref3 << endl;
	cout << endl << endl;

	// ������ �����ϴ� ����
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dref) = dptr;

	// **�� ���� �������� �ּҸ� �޾ƿ´�
	cout << "ref value: " << ref << endl;
	cout << "pref value: " << *pref << endl;
	cout << "dref value: " << **dref << endl;

	return 0;
}
#include <iostream>
using namespace std;

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �Ű������� ����Ʈ ��
	����Ʈ ���� �⺻������ �����Ǿ� �ִ� ��
*/

int Add(int num1 = 1) {

	return num1;
}

int Add(int num1, int num2 = 2) {

	return num1 + num2;
}

int Multi(int num1 = 1, int num2 = 2) {

	return num1 * num2;
}

int main()
{

	cout << Add() << endl;
	// Add(2); // C#�� �޸� ȣ���� ��ȣ�ϴٴ� ���� ��� 
			   // C#������ Add(num1 = 1)�� ȣ��ȴ�

	cout << Multi() << endl;		// 1 * 2 = 2
	cout << Multi(2) << endl;		// 2 * 2 = 4
	cout << Multi(1, 2) << endl;	// 1 * 2 = 2

	return 0;
}
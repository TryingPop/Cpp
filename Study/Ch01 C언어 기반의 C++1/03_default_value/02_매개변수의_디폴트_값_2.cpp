#include <iostream>
using namespace std;

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : �Ű������� ����Ʈ ��
	����Ʈ �� �����ϴ� �ٸ� ���
*/

// �Լ��� ����
int Add(int num1 = 1, int num2 = 2); 

int main()
{

	cout << "Add() : " << Add() << endl;
	cout << "Add(5) : " << Add(5) << endl;
	cout << "Add(1, 2) : " << Add(1, 2) << endl;

	return 0;
}

// �Լ��� ����
int Add(int num1, int num2) {

	return num1 + num2;
}
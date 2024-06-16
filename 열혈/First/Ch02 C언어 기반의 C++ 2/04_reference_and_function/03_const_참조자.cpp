/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : const ������
	const �������� ��� ����
*/

#include <iostream>
using namespace std;

int Add(const int& num1, const int& num2);

int main(void)
{

	// const ������
	const int num = 20;

	// int& ref = num;		// ��ȯ�� �� �־ �����Ͽ��� ���� ���
	const int& ref1 = num;	// ������ ���� ��ȯ�ϸ� ���� ����

	// �����ڴ� ����� ���� ���Ѵٰ� �ߴµ�, �Ʒ��� ���� ���� �����̴�
	// 20�� literal�̶� ���� ������ �Ѿ�� ������� ���
	// const �����ڴ� 20�� �����ϴ� �ӽ� ������ �����Ѵ�
	// ������ ref2�� ������ �ӽú����� ���������ν�
	// ref2�� 10�� �����ϰ� �ִ�
	const int& ref2 = 20;

	cout << "num : " << ref1 << endl;
	cout << "ref2 : " << ref2 << endl;

	cout << "Add(3, 4) : " << Add(3, 4) << endl;

	cout << "ref2 : " << ref2 << endl;
}

int Add(const int& num1, const int& num2) {

	return num1 + num2;
}
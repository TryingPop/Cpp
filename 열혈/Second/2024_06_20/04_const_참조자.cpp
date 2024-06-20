/*
��¥ : 2024. 6. 20
�̸� : �輺��
���� : const �������� �� �ٸ� Ư¡
	���� p88 ~ 89

	const ������ ���ؼ� ���� num�� ���ȭ �ߴµ�,
	�ٸ� ������ ref�� ���� �̸� �����Ѵٸ� num�� ���ȭ�� �ǹ̰� ����
	C++ �����Ϸ��� �ش� �κ��� ������� �ʴ´�

	num�� ����� ����Ǹ� num�� �����ڵ� const ���� ����ϰ� �ִ�
	const ������ ������ ������ ������ ����Ų��
*/

#include <iostream>

using namespace std;

int main(void)
{

	const int num1 = 10;
	// int& ref1 = num1;				// ������ ���� �߻�
	const int& ref1 = num1;				// �̻���� �ߵȴ�

	int num2 = 10;
	const int& ref2 = num2;

	num2 = 20;
	// ref2 = 100;						// ������ ���� �߻�

	cout << "num1: " << num1 << endl;	// 10
	cout << "ref1: " << ref1 << endl;	// 10

	cout << "num2: " << num2 << endl;	// 20
	cout << "ref2: " << ref2 << endl;	// 20

	return 0;
}
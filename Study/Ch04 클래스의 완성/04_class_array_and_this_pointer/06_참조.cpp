/*
��¥ : 2023. 1. 29
�̸� : �輺��
���� : ����
	������ ����

*/

#include <iostream>
using namespace std;

int main(void)
{

	int num = 1;
	int& ref = num;

	// ���� num�� ������ �� �մ� ���� ���� ������ ref�� ���޵Ǿ�
	// ������ ���� ref�� ���� num�� �����ϰ� �ȴ�

	cout << &num << endl;

	cout << "ref" << endl;
	cout << ref << endl;
	cout << &ref << endl;
	return 0;
}
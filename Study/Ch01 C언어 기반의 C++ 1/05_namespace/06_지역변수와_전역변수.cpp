#include <iostream>
using namespace std; // std �̸� ������ �޼ҵ带 �����ϰ� �ҷ����� ���� ����

/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : ���� ���� ������
	���������� ��������
*/

// ��������
int val = 0;

int SimpleFunc(void) {

	// ���� ����
	// �Լ��� ����Ǹ� ���� ������ �޸𸮿��� �������
	int val = 20;
	val += 3;
	// ���� ����
	::val += 7;

	return 0;
}

int main()
{

	cout << "���� ���� val : " << val << endl;	// 0
	SimpleFunc();
	cout << "���� ���� val : " << val << endl;	// 7
	return 0;
}

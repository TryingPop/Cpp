/*
��¥ : 2024. 6. 17
�̸� : �輺��
���� : �������� ������(Scope Resolution Operator)�� �� �ٸ� ���
	���� p49 ~ 50

	���������� �̸��� ���������� �̸��� ���� ���,
	���������� ���������� ���� ��������

	�׷��� �������� �����ڸ� ���� ������������ ������ �� �ִ�
*/

#include <iostream>

using namespace std;

int num = 1;

int main(void)
{

	int num = 5;
	cout << "���� ���� num: " << num << endl;		// 5
	cout << "���� ���� num: " << ::num << endl;		// 1

	return 0;
}
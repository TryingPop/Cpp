/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : new�� ������
	������ ���� ���� �Ҵ�� ���� ����
*/

#include <iostream>
using namespace std;

int main(void) 
{

	int* ptr = new int;
	int& ref = *ptr;
	ref = 20;
	cout << *ptr << endl;	// 20

	return 0;
}
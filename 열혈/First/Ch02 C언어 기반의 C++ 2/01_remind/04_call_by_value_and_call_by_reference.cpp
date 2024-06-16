/*
��¥ : 2023. 1. 23
�̸� : �輺��
���� : call by value & call by reference
	���� ���� ȣ��, ������ ���� ȣ���� ����
*/

#include <iostream>
using namespace std;

// �Լ� ����
void ValFunc(int num);
void RefFunc(int* num);


int main(void) 
{

	int val1 = 0, val2 = 0;
	ValFunc(val1);
	RefFunc(&val2);

	cout << "val1 : " << val1 << endl;	// 0
	cout << "val2 : " << val2 << endl;	// 1
}

// Call by Value
void ValFunc(int num) {

	// ���� ���� num�� �Ҵ�ǰ� �Ű������� ���� ������ ��´�
	// ������ ���� �����ϰ� �Ű����� num�� ���� ��ȭ�� ����
	// �Լ��� ���� �Ǿ �Ű����� ���� ��ȭ�� ����
	num += 1;

}

// Call by Reference
void RefFunc(int* num) {

	// �ּҸ� ����Ű�� ���� num�� ���� num�� �ּҸ� �ִ´�
	// *num�� �ּҷ� ã�ư� �ش��ϴ� ���� �����Ѵ�
	// �Լ��� ����Ǹ� �Ű������� ���� 1 ���� �Ѵ�
	*num += 1;
}
/*
��¥ : 2023. 1. 25
�̸� : �輺��
���� : ���� 80p ����1
	�����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����Ͽ���
		1. ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
		2. ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�
*/

#include<iostream>
using namespace std;

void IncreOne(int& num) {

	num++;
}

void InverSign(int& num) {

	num *= -1;
}

int main(void)
{

	int val = 20;
	IncreOne(val);
	cout << val << endl;	// 21

	InverSign(val);
	cout << val << endl;	// -21
	return 0;
}
/*
��¥ : 2023. 1. 24
�̸� : �輺��
���� : ���� 80p ����1
	�����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����Ͽ���
		1. ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
		2. ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�
*/

// 1���� 
void Func1(int& num) {

	num++;
}

// ��ȣ ��ȯ �Լ�
void Func2(int& num) {

	num = -num;
}

// �� ���� �Ǵ��� Ȯ��
#include <iostream>
using namespace std;

int main(void)
{
	int val1 = 2;
	int val2 = 3;

	Func1(val1);
	Func2(val2);

	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;
}
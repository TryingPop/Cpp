/*
��¥ : 2023. 1. 22
�̸� : �輺��
���� : ������
	*�� �ǹ̿� &�� �ǹ̸� �˾ƺ���
*/

#include<iostream>
using namespace std;

int main(void)
{
	
	int num1 = 10;
	int num2 = 20;

	// int�� ���� ����, char, float, double �� �ؼ��� ��� ����
	// int* ������ ���⼭ int* �� �ǹ��ϴ� ���� int������ �ּҸ� ��� �����ͷ� ���� �ȴ�
	// Win 32bit������ 4 byte, 64bit������ 8 byte ũ��!
	// ������ �� ������ *�������� �Է��ϴ� ������ ���� ������ �� �ִ�.
	int* ptr;	// �ʱ�ȭ ���� ������ ���� �� ����

	// &�� �ǹ��ϴ� ���� ������ �ּҶ�� �����ϸ� �ȴ�
	cout << "num1�� �ּ�" << &num1 << endl;
	cout << "num2�� �ּ�" << &num2 << endl;

	ptr = &num1;
	cout << "ptr �ּ�" << ptr << endl;
	cout << "ptr ��" << *ptr << endl;

	ptr = &num2;
	cout << "ptr �ּ�" << ptr << endl;
	cout << "ptr ��" << *ptr << endl;
}
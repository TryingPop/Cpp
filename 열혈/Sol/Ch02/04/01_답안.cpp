/*
��¥ : 2023. 1. 25
�̸� : �輺��
���� : ���� 99p ����1
	���� ǥ���Լ��� ȣ���ϴ� ������ �����,
	C++�� ����� �����ؼ� ������.
	�׸��� ������ ������ ����� ������,
	�Ʒ��� �Լ����� �ּ� 1ȸ �̻� ȣ���ؾ� �Ѵ�.
	����� ���� �Լ����� C����� ��� <string.h>�� ����Ǿ� �ִ�.
		- strlen : ���ڿ��� ���� ���
		- strcat : ���ڿ��� �ڿ� �����̱�
		- strcpy : ���ڿ� ����
		- strcmp : ���ڿ��� ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{

	char* str1 = "ABC 123 ";
	char* str2 = "DEF 456 ";

	char str3[50];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	strcpy(str3, str1);
	strcpy(str3, str1);
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) {
		cout << "���ڿ��� ����." << endl;
	}
	else {

		cout << "���ڿ��� ���� �ʴ�." << endl;
	}
	return 0;
}
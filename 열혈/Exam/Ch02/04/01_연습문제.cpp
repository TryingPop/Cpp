/*
��¥ : 2023. 1. 24
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
	
	char str1[15];
	char str2[25];

	char name[100];

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;

	if (strlen(name) <= 4) {

		strcpy(str1, name);
		strcat(str1, "��");
		cout << "�̸��� ª�� "  << str1 << " �ȳ��ϼ���" << endl;
	}
	else if (strlen(name) < 9) {

		strcpy(str2, name);
		strcat(str2, "��");
		cout << "�̸��� �� " << str2 << " �ȳ��ϼ���" << endl;
	}
	else {
		cout << "�̸��� �ʹ� ����." << endl;
	}

	return 0;
}
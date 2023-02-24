/*
��¥ : 2023. 2. 24
�̸� : �輺��
���� : ���ܻ�Ȳ�� �߻��� ��ġ�� ���ܻ�Ȳ�� ó���ؾ� �ϴ� ��ġ�� �ٸ� ���
	�Լ� ������ ���� �����͸� �����ϸ�, 
	return ���� ������ ���� �Լ��� ����� ���������� �Լ��� ������ ���� ������ ���� �ȴ�
*/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int StoI(char* str) {

	int len = strlen(str);
	int num = 0;

	for (int i = 0; i < len; i++) {

		if (str[i] < '0' || str[i] > '9') {

			throw str[i];
		}

		// ���� ��ȯ �ڵ�
		// pow((double)10, (len - 1) - i) �ڸ� ã�� �ڵ�
		// str[i] + (7 - '7') �� �ڸ��� ã�� �ڵ� �ڿ� 7 - '7' ��� - '0'�� �ص� �ȴ�
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}

	return num;
}

int main(void)
{

	char str1[100];
	char str2[200];

	while (1) {

		cout << "�� ���� ���� �Է�: ";
		cin >> str1 >> str2;

		try {

			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch) {

			cout << "���� " << ch << "�� �ԷµǾ����ϴ�." << endl;
			cout << "���Է� �����մϴ�." << endl << endl;
		}
	}

	cout << "���α׷��� �����մϴ�." << endl;
	return 0;
}
#include <iostream>
#include <string>

/*
��¥ : 2024. 2. 7
�̸� : �輺��
���� : ��ҹ��� �ٲ㼭 ����ϱ�
	���ڿ��� �Է� ������ ��ҹ��� �ٲ㼭 ����ϱ�
*/

using namespace std;

int main4(void)
{

	string str;
	cin >> str;

	char diff = 'a' - 'A';

	for (int i = 0; i < str.length(); i++) 
	{

		if (str[i] >= 'a') str[i] -= diff;
		else str[i] += diff;
	}

	cout << str;
	return 0;
}
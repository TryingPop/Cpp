#include <iostream>
#include <string>

/*
��¥ : 2024. 2. 8
�̸� : �輺��
���� : ���ڿ� ������
	�־��� ���ڿ��� �ϳ��� �б�
*/

using namespace std;

int main3(void)
{

	string str;
	cin >> str;


	for (const char c: str)
	// for (int i = 0; i < str.length(); i++)
	{

		// cout << str[i] << '\n';
		cout << c << '\n';
	}
	return 0;
}
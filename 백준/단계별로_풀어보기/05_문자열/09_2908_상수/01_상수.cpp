/*
��¥ : 2024. 8. 8
�̸� : �輺��
���� : ���
	������ȣ : 2908��

	����, ���� ������
*/

#include <iostream>
#include <string>

using namespace std;

inline int RevStrToInt(string _str)
{

	int ret = 0;
	for (int i = _str.length() - 1; i >= 0; i--) 
	{

		ret = ret * 10 + _str[i] - '0';
	}

	return ret;
}

int main(void)
{

	string str;
	int a, b;

	cin >> str;
	a = RevStrToInt(str);
	cin >> str;
	b = RevStrToInt(str);
	
	cout << (a < b ? b : a);

	return 0;
}
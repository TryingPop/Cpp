/*
��¥ : 2024. 8. 12
�̸� : �輺��
���� : ���� ��ȯ
	������ȣ : 2745��

	����, ����, ���ڿ� ������
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

inline int GetVal(string _str, int _n)
{

	int ret = 0;

	for (char c : _str)
	{

		if ('A' <= c && c <= 'Z') ret = ret * _n + c - 'A' + 10;
		else ret = ret * _n + c - '0';
	}

	return ret;
}

int main(void)
{

	string str;
	int n;

	FAST_IO;

	cin >> str >> n;

	cout << GetVal(str, n);

	return 0;
}
/*
��¥ : 2024. 8. 6
�̸� : �輺��
���� : ���ڿ� ���ڿ�
	������ȣ : 27866��

	����, ���ڿ� ������
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false);

using namespace std;

int main(void)
{

	string str;
	int idx;
	FAST_IO;

	cin >> str >> idx;

	cout << str[idx - 1];
	return 0;
}
/*
��¥ : 2024. 8. 7
�̸� : �輺��
���� : �ܾ��� ����
	������ȣ : 1152��

	����, ���ڿ� ������
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	string str;
	FAST_IO;

	int ret = 0;

	while (cin >> str)
	{

		ret++;
	}

	cout << ret;
	return 0;
}
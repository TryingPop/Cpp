/*
��¥ : 2024. 8. 9
�̸� : �輺��
���� : �Ӹ�������� Ȯ���ϱ�
	������ȣ : 10988��

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

	cin >> str;

	int ret = 1;
	for (int i = 0; i < str.length(); i++)
	{

		int j = str.length() - 1 - i;

		if (j <= i) break;
		if (str[i] == str[j]) continue;

		ret = 0;
		break;
	}

	cout << ret;
	return 0;
}
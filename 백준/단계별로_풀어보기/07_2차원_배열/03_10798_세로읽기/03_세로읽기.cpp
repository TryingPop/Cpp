/*
��¥ : 2024. 8. 11
�̸� : �輺��
���� : �����б�
	������ȣ : 10798��

	����, ���ڿ� ������
*/

#include <iostream>
#include <string>
#include <vector>

#define FAST_IO cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	vector<string> str(5);
	int col = 0;
	FAST_IO;

	for (int i = 0; i < 5; i++)
	{

		cin >> str[i];
		if (col < str[i].length()) col = str[i].length();
	}

	for (int c = 0; c < col; c++)
	{

		for (int r = 0; r < 5; r++)
		{

			if (str[r].length() <= c) continue;
			cout << str[r][c];
		}
	}

	return 0;
}
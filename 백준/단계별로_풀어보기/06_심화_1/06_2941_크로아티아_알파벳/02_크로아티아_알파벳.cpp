/*
��¥ : 2024. 8. 10
�̸� : �輺��
���� : ũ�ξ�Ƽ�� ���ĺ�
	������ȣ : 2941��

	����, ���ڿ� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	string str;
	int ret = 0;
	char cur = ' ', prev;
	FAST_IO;

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{

		ret++;

		prev = cur;
		cur = str[i];

		if (i > 0)
		{

			if (cur == '=')
			{

				if (prev == 'c' || prev == 's') ret--;
				else if (prev == 'z')
				{

					if (i > 1 && str[i - 2] == 'd') ret -= 2;
					else ret--;
				}
			}
			else if (cur == 'j')
			{

				if (prev == 'l' || prev == 'n') ret--;
			}
			else if (cur == '-')
			{

				if (prev == 'c' || prev == 'd') ret--;
			}
		}
	}

	cout << ret;

	return 0;
}
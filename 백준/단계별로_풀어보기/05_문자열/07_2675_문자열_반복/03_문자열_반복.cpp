/*
��¥ : 2024. 8. 7
�̸� : �輺��
���� : ���ڿ� �ݺ�
	������ȣ : 2675��

	����, ���ڿ� ������
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void)
{

	int n, r;
	string str;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> r >> str;

		for (char c : str)
		{

			for (int j = 0; j < r; j++)
			{

				cout << c;
			}
		}

		cout << endl;
	}

	return 0;
}
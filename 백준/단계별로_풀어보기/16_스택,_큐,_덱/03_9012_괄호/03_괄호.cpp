/*
��¥ : 2024. 8. 30
�̸� : �輺��
���� : ��ȣ
	������ȣ : 9012��

	�ڷᱸ��, ���ڿ�, ���� ������
*/

#include <iostream>
#include <string>
#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	const string YES = "YES\n";
	const string NO = "NO\n";

	int n, chk;
	string temp;

	FAST_IO;

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		chk = 0;

		for (const char c : temp)
		{

			if (c == '(') chk++;
			else 
			{

				if (chk) chk--;
				else 
				{ 
					
					chk = -1;
					break;
				}
			}
		}

		cout << ((chk == 0) ? YES : NO);
	}

	return 0;
}
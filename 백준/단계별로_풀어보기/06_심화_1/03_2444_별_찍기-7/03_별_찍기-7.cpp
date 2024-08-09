/*
��¥ : 2024. 8. 9
�̸� : �輺��
���� : �� ��� - 7
	������ȣ : 2444��

	���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false);

#define EMPTY	' '
#define STAR	'*'
#define ENDL	'\n'
using namespace std;

int main(void)
{

	int n;
	FAST_IO;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{

		for (int j = n - i; j > 0; j--)
		{

			cout << EMPTY;
		}

		for (int j = 0; j < 2 * i - 1; j++)
		{

			cout << STAR;
		}

		cout << ENDL;
	}

	for (int i = 1; i <= n; i++)
	{

		for (int j = 0; j < i; j++)
		{

			cout << EMPTY;
		}

		for (int j = 0; j < 2 * (n - i) - 1; j++)
		{

			cout << STAR;
		}

		cout << ENDL;
	}

	return 0;
}
/*
��¥ : 2024. 8. 3
�̸� : �輺��
���� : �� ��� - 2
	������ȣ : 2439��

	���� ������
*/

#include <iostream>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define STAR '*'
#define EMPTY ' '
#define endl '\n'

using namespace std;

int main(void)
{

	int n;
	fastio;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{

		for (int j = n - i; j > 0; j--)
		{

			cout << EMPTY;
		}

		for (int j = 0; j < i; j++)
		{

			cout << STAR;
		}

		cout << endl;
	}
}
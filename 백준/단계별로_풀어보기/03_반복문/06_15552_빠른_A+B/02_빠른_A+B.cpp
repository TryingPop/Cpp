/*
��¥ : 2024. 8. 2
�̸� : �輺��
���� : ���� A+B
	������ȣ : 15552��

	����, ����, ��Ģ���� ������
*/

#include <iostream>

#define fastio	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void)
{

	int test, a, b;
	fastio;
	cin >> test;

	while (test--)
	{

		cin >> a >> b;
		cout << a + b << endl;
	}

	return 0;
}
/*
��¥ : 2024. 8. 1
�̸� : �輺��
���� : A+B-3
	������ȣ : 10950��

	����, ����, ��Ģ���� ������
*/

#include <iostream>

#define endl '\n'
#define fastio cin.tie(0);		\
				cout.tie(0);	\
				ios_base::sync_with_stdio(false)

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
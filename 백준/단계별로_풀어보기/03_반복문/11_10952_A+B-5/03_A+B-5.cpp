/*
��¥ : 2024. 8. 3
�̸� : �輺��
���� : A + B - 5
	������ȣ : 10952��

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

	int a, b;
	fastio;
	
	while (true)
	{

		cin >> a >> b;
		if (a == 0 && b == 0) break;

		cout << a + b << endl;
	}

	return 0;
}
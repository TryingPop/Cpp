/*
��¥ : 2024. 7. 28
�̸� : �輺��
���� : ����
	������ȣ : 2588��

	����, ��Ģ���� ������
*/

#include <iostream>

#define endl '\n'

using namespace std;

int main(void)
{

	int a, b;
	cin >> a >> b;

	int c = b;
	while (c)
	{

		cout << a * (c % 10) << endl;
		c /= 10;
	}

	cout << a * b;
	return 0;
}
/*
��¥ : 2024. 8. 12
�̸� : �輺��
���� : ��Ź�� ���� ����
	������ȣ : 2720��

	����, �׸���, ��Ģ���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define EMPTY	' '
#define endl	'\n'
using namespace std;

int main(void)
{

	int test, n;
	int a, b, c, d;
	FAST_IO;

	cin >> test;

	while (test--)
	{

		cin >> n;

		a = n / 25;
		n %= 25;

		b = n / 10;
		n %= 10;

		c = n / 5;
		n %= 5;

		d = n;

		cout << a << EMPTY << b << EMPTY << c << EMPTY << d << endl;
	}

	return 0;
}
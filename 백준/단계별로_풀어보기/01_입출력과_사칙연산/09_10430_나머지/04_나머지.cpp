/*
��¥ : 2024. 7. 28
�̸� : �輺��
���� : ������
	������ȣ : 10430��

	����, ����, ��Ģ���� ������
*/

#include <iostream>

#define endl '\n'

using namespace std;

int main(void)
{

	int a, b, c;

	cin >> a >> b >> c;

	cout << (a + b) % c << endl;
	cout << (a % c + b % c) % c << endl;
	cout << (a * b) % c << endl;
	cout << ((a % c) * (b % c)) % c;

	return 0;
}
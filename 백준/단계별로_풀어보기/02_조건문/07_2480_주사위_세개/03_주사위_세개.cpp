/*
��¥ : 2024. 7. 31
�̸� : �輺��
���� : �ֻ��� ����
	������ȣ : 2480��

	����, ����, ��Ģ����, ���� ���� �б� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b, c;

	cin >> a >> b >> c;

	int ret;
	if (a == b && b == c) ret = 10'000 + 1'000 * a;
	else if (a == b) ret = 1'000 + 100 * a;
	else if (b == c) ret = 1'000 + 100 * b;
	else if (c == a) ret = 1'000 + 100 * c;
	else if (a > b && a > c) ret = 100 * a;
	else if (b > c && b > a) ret = 100 * b;
	else ret = 100 * c;

	cout << ret;
	return 0;
}
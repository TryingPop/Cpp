/*
��¥ : 2024. 8. 19
�̸� : �輺��
���� : �˰��� ���� - ������ ǥ�� 1
	������ȣ : 24313��

	���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a1, a0, c, n0, ret;

	cin >> a1 >> a0 >> c >> n0;

	ret = a1 * n0 + a0 <= c * n0 && a1 <= c;
	cout << ret;
	return 0;
}
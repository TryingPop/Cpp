/*
��¥ : 2024. 8. 20
�̸� : �輺��
���� : ������ ���鰭���Դϴ�
	������ȣ : 19532��

	����, ���Ʈ���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;

	y = (c * d - a * f) / (b * d - a * e);
	x = (c * e - b * f) / (a * e - b * d);

	cout << x << ' ' << y;

	return 0;
}
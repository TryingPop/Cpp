/*
��¥ : 2024. 8. 13
�̸� : �輺��
���� : �����̴� �ö󰡰� �ʹ�
	������ȣ : 2869��

	����
*/

#include <iostream>

using namespace std;

int main(void)
{

	int a, b, v, ret = 1;
	cin >> a >> b >> v;

	v -= a;
	if (v)
	{

		v--;
		ret += 1 + v / (a - b);
	}

	cout << ret;
	return 0;
}
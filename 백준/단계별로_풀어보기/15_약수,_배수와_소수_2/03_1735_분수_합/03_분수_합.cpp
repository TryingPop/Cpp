/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : �м� ��
	������ȣ : 1735��

	����, ������, ��Ŭ���� ȣ���� ������
*/

#include <iostream>

using namespace std;

inline int GetGCD(int _a, int _b)
{

	while (_b)
	{

		int temp = _a % _b;
		_a = _b;
		_b = temp;
	}

	return _a;
}

int main(void)
{

	int a, b, c, d, up, down, gcd;
	cin >> a >> b >> c >> d;

	up = a * d + b * c;
	down = b * d;

	gcd = GetGCD(up, down);
	cout << up / gcd << ' ' << down / gcd;

	return 0;
}
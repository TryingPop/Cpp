/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : ���μ�
	������ȣ : 2485��

	����, ������, ��Ŭ���� ȣ���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

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

	int n, s, temp, gcd, len;
	FAST_IO;

	cin >> n >> s >> temp;
	gcd = temp - s;
	for (int i = 2; i < n; i++)
	{

		cin >> temp;
		gcd = GetGCD(gcd, temp - s);
	}

	len = (temp - s) / gcd;
	cout << len - n + 1;
	
	return 0;
}
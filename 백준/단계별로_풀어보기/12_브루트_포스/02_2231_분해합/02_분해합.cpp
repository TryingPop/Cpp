/*
��¥ : 2024. 8. 20
�̸� : �輺��
���� : ������
	������ȣ : 2231��

	���Ʈ���� ������
*/

#include <iostream>

#define Max(X, Y)	(((X) < (Y)) ? (Y) : (X))
using namespace std;


inline int CompositSum(int _n)
{

	int ret = _n;

	while (_n > 0)
	{

		ret += _n % 10;
		_n /= 10;
	}

	return ret;
}

int main(void)
{

	int n, ret = 0;
	cin >> n;

	for (int i = Max(n - 70, 0); i <= n; i++)
	{

		if (CompositSum(i) != n) continue;
		ret = i;
		break;
	}

	cout << ret;

	return 0;
}
/*
��¥ : 2024. 9. 3
�̸� : �輺��
���� : �����ž
	������ȣ : 24723��

	����, ��Ģ���� ������
*/

#include <iostream>

using namespace std;

inline int GetPow(int _n, int _exp) 
{

	int ret = 1;
	while (_exp)
	{

		if (_exp & 1) ret *= _n;

		_exp >>= 1;
		_n *= _n;
	}

	return ret;
}

int main(void)
{

	int n;
	cin >> n;

	cout << GetPow(2, n);
	return 0;
}
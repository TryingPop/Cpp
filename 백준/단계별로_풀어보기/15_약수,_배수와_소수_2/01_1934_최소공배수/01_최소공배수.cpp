/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : �ּҰ����
	������ȣ : 1934��

	����, ������, ��Ŭ���� ȣ���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

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

inline int GetLCM(int _a, int _b)
{

	int gcd = GetGCD(_a, _b);
	return _a * (_b / gcd);
}

int main(void)
{

	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> a >> b;
		cout << GetLCM(a, b) << endl;
	}

	return 0;
}
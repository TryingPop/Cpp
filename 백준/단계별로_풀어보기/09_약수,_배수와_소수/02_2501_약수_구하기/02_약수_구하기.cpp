/*
��¥ : 2024. 8. 14
�̸� : �輺��
���� : ��� ���ϱ�
	������ȣ : 2501��

	����, ���Ʈ���� ������
*/

#include <iostream>

using namespace std;

inline int GetRet(int _n, int _k) 
{

	for (int i = 1; i <= _n; i++)
	{

		if (_n % i) continue;
		_k--;

		if (_k) continue;

		return i;
	}

	return 0;
}

int main(void)
{

	int n, k;
	cin >> n >> k;

	cout << GetRet(n, k);
	return 0;
}
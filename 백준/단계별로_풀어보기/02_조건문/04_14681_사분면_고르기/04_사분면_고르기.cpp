/*
��¥ : 2024. 7. 30
�̸� : �輺��
���� : ��и� ����
	������ȣ : 14681��

	����, ������
*/

#include <iostream>

using namespace std;

inline int FindQuadrant(int _x, int _y)
{

	if (_x > 0)
	{

		if (_y > 0) return 1;
		else return 4;
	}
	else
	{

		if (_y > 0) return 2;
		else return 3;
	}
}

int main(void)
{

	int x, y;
	cin >> x >> y;

	cout << FindQuadrant(x, y);

	return 0;
}
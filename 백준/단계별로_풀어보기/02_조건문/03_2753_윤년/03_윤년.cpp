/*
��¥ : 2024. 7. 30
�̸� : �輺��
���� : ����
	������ȣ : 2753��

	����, ����, ��Ģ���� ������
*/

#include <iostream>

using namespace std;

inline bool IsLeapYear(int _year)
{

	if (_year % 400 == 0
		|| (_year % 100 && _year % 4 == 0)) return true;

	return false;
}

int main(void)
{

	int year;
	cin >> year;

	cout << IsLeapYear(year) ? '1' : '0';
	return 0;
}
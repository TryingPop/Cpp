/*
��¥ : 2024. 7. 31
�̸� : �輺��
���� : �˶� �ð�
	������ȣ : 2884��

	����, ��Ģ���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int hour, minute;
	cin >> hour >> minute;

	minute -= 45;
	if (minute < 0)
	{

		minute += 60;
		hour -= 1;
		if (hour < 0) hour += 24;
	}
	
	cout << hour << ' ' << minute;
	return 0;
}
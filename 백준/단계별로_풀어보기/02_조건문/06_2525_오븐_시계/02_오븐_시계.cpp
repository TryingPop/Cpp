/*
��¥ : 2024. 7. 31
�̸� : �輺��
���� : ���� �ð�
	������ȣ : 2525��

	����, ��Ģ���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int h, m, temp;
	cin >> h >> m >> temp;

	int addH, addM;
	addH = temp / 60;
	addM = temp % 60;

	m += addM;
	if (60 <= m) 
	{

		m -= 60;
		h += 1;
	}

	h += addH;
	if (24 <= h) h %= 24;

	cout << h << ' ' << m;
	return 0;
}
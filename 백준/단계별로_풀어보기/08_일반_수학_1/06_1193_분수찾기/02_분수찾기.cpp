/*
��¥ : 2024. 8. 13
�̸� : �輺��
���� : �м�ã��
	������ȣ : 1193��

	����, ���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int n;
	cin >> n;

	int cnt = 1;
	bool isL = true;
	while (n > cnt)
	{

		n -= cnt++;
		isL = !isL;
	}

	cout << (isL ? (cnt + 1 - n) : n) << '/' << (isL ? n : (cnt + 1 - n));
	return 0;
}
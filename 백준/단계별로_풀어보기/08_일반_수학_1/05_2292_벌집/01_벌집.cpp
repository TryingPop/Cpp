/*
��¥ : 2024. 8. 13
�̸� : �輺��
���� : ����
	������ȣ : 2292��

	���� ������
*/

#include <iostream>

using namespace std;

int main(void)
{

	int n;
	cin >> n;

	int ret = 1;
	n--;
	int diff = 6;

	while (n > 0)
	{

		n -= diff;
		ret++;
		diff += 6;
	}

	cout << ret;
	return 0;
}
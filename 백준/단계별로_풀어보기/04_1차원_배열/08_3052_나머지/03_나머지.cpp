/*
��¥ : 2024. 8. 5
�̸� : �輺��
���� : ������
	������ȣ : 3052��

	����, ��Ģ���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

bool use[42];

int main(void)
{

	int n, ret = 0;
	FAST_IO;

	for (int i = 0; i < 10; i++)
	{

		cin >> n;
		n %= 42;

		if (use[n]) continue;
		use[n] = true;
		ret++;
	}

	cout << ret;

	return 0;
}
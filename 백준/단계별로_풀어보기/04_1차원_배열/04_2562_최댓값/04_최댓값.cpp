/*
��¥ : 2024. 8. 4
�̸� : �輺��
���� : �ִ�
	������ȣ : 2562��

	���� ������
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'
using namespace std;

int main(void)
{

	int num, max = -1, idx = -1;

	FAST_IO;
	for (int i = 1; i <= 9; i++)
	{

		cin >> num;

		if (max < num)
		{

			max = num;
			idx = i;
		}
	}

	cout << max << endl;
	cout << idx;

	return 0;
}
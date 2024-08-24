/*
��¥ : 2024. 8. 24
�̸� : �輺��
���� : ��Ʈ�λ��̵�
	������ȣ : 1427��

	���ڿ�, ���� ������
*/

#include <iostream>
#include <vector>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	vector<int> cnt(10, 0);
	string nums;

	FAST_IO;

	cin >> nums;

	for (char c : nums)
	{

		cnt[c - '0']++;
	}

	for (int i = 9; i >= 0; i--)
	{

		if (!cnt[i]) continue;
		for (int j = 0; j < cnt[i]; j++)
		{

			cout << i;
		}
	}

	return 0;
}
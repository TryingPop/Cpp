/*
��¥ : 2024. 8. 7
�̸� : �輺��
���� : ���ĺ� ã��
	������ȣ : 10809��

	����, ���ڿ� ������
*/

#include <iostream>
#include <vector>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	string str;
	vector<int> cnt(26, -1);

	FAST_IO;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{

		int idx = str[i] - 'a';
		if (cnt[idx] != -1) continue;
		cnt[idx] = i;
	}

	for (int ret : cnt)
	{

		cout << ret << ' ';
	}
	return 0;
}
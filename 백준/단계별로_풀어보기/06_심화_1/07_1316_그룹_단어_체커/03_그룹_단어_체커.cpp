/*
��¥ : 2024. 8. 10
�̸� : �輺��
���� : �׷� �ܾ� üĿ
	������ȣ : 1316��

	����, ���ڿ� ������
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

inline bool ChkGroupWord(string& _str, vector<bool>& _use)
{

	fill(_use.begin(), _use.end(), false);

	char b = ' ';
	for (const char c : _str)
	{

		if (c == b) continue;
		if (_use[c - 'a']) return false;
		_use[c - 'a'] = true;
		b = c;
	}

	return true;
}

int main(void)
{

	int n, ret = 0;
	string str;
	vector<bool> use(26, false);

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> str;
		if (ChkGroupWord(str, use)) ret++;
	}

	cout << ret;
	return 0;
}
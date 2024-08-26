/*
��¥ : 2024. 8. 26
�̸� : �輺��
���� : ���ڿ� ����
	������ȣ : 14425��

	�ڷᱸ��, ���ڿ�, �ؽ� ������
*/

#include <iostream>
#include <string>
#include <unordered_set>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, m, ret = 0;
	string temp;
	unordered_set<string> strs;

	FAST_IO;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		strs.insert(temp);
	}

	for (int i = 0; i < m; i++)
	{

		cin >> temp;
		ret += strs.count(temp);
	}

	cout << ret;
	return 0;
}
/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : ���� �ٸ� �κ� ���ڿ��� ����
	������ȣ : 11478��

	�ڷᱸ��, ���ڿ�, �ؽ� ������
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{

	unordered_set<string> chk;
	string str, sub;
	int ret = 0;

	cin >> str;

	for (int i = 1; i <= str.length(); i++)
	{

		for (int j = 0; j <= str.length() - i; j++)
		{

			sub = str.substr(j, i);
			if (chk.count(sub)) continue;
			ret++;
			chk.insert(sub);
		}
	}

	cout << ret;
	return 0;
}
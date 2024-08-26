/*
��¥ : 2024. 8. 26
�̸� : �輺��
���� : ȸ�翡 �ִ� ���
	������ȣ : 7785��

	�ڷᱸ��, �ؽ� ������
*/

#include <iostream>
#include <string>
#include <set>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'
using namespace std;

int main(void)
{

	set<string, greater<string>> remains;
	string name, t;
	const string ENTER = "enter", LEAVE = "leave";

	int n;

	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> name >> t;

		if (t == ENTER)
			remains.insert(name);
		else
			remains.erase(name);
	}

	for (string name : remains)
	{

		cout << name << endl;
	}

	return 0;
}
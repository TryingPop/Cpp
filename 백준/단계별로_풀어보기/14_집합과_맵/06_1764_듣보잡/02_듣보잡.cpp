/*
��¥ : 2024. 8. 28
�̸� : �輺��
���� : �躸��
	������ȣ : 1764��

	�ڷᱸ��, ���ڿ�, ����, �ؽ� ������
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

	int n, m, ret1 = 0;
	string temp;
	set<string> chk, ret2;

	FAST_IO;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		chk.insert(temp);
	}

	for (int i = 0; i < m; i++)
	{

		cin >> temp;
		if (chk.count(temp)) 
		{ 
			
			ret1++;
			ret2.insert(temp); 
		}
	}

	cout << ret1 << endl;
	for (string str : ret2)
	{

		cout << str << endl;
	}
	return 0;
}
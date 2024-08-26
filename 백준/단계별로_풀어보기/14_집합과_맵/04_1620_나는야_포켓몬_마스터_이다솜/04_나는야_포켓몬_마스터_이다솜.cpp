/*
��¥ : 2024. 8. 26
�̸� : �輺��
���� : ���¾� ���ϸ� ������ �̴ټ�
	������ȣ : 1620��

	�ڷᱸ��, �ؽ� ������
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

#define endl	'\n'

using namespace std;

inline bool ChkNum(const string& _temp) 
{

	return _temp[0] <= '9' && '0' <= _temp[0];
}

inline int ConvertNum(const string& _str)
{

	int ret = 0;
	for (const char c : _str)
	{

		ret = ret * 10 + c - '0';
	}

	return ret;
}

int main(void)
{

	unordered_map<string, int> sTn;
	vector<string> nTs;

	int n, m, num = 1;
	string temp;

	FAST_IO;

	cin >> n >> m;

	nTs.push_back("");
	for (int i = 0; i < n; i++)
	{

		cin >> temp;
		nTs.push_back(temp);
		sTn[temp] = num++;
	}

	for (int i = 0; i < m; i++)
	{

		cin >> temp;
		if (ChkNum(temp))
		{

			num = ConvertNum(temp);
			cout << nTs[num] << endl;
		}
		else
			cout << sTn[temp] << endl;
	}
	return 0;
}
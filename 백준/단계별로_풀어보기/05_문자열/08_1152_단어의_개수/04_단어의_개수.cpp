/*
��¥ : 2024. 8. 7
�̸� : �輺��
���� : �ܾ��� ����
	������ȣ : 1152��

	����, ���ڿ� ������
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	string str;
	FAST_IO;

	int ret = 0;

#if first
	while (cin >> str)
	{

		ret++;
	}
#else

	while (true)
	{

		char c = cin.get();
		if (c == ' ')
		{

			if (str == "") continue;
			ret++;
			str.clear();
			continue;
		}
		else if (c == EOF || c == '\r' || c == '\n') 
		{ 
			
			if (str != "") ret++;
			break; 
		}

		str.push_back(c);
	}
#endif
	cout << ret;
	return 0;
}
/*
��¥ : 2024. 8. 7
�̸� : �輺��
���� : ������ ��
	������ȣ : 11720��
*/

#include <iostream>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	int n, ret = 0;
	string str;
	FAST_IO;

	cin >> n >> str;
	for (int i = 0; i < n; i++)
	{

		ret += str[i] - '0';
	}
	
	cout << ret;
	return 0;
}
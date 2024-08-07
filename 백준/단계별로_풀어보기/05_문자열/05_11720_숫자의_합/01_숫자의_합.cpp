/*
날짜 : 2024. 8. 7
이름 : 배성훈
내용 : 숫자의 합
	문제번호 : 11720번
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
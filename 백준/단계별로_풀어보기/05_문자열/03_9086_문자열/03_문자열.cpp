/*
날짜 : 2024. 8. 6
이름 : 배성훈
내용 : 문자열
	문제번호 : 9086번

	구현, 문자열 문제다
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

#define endl '\n'
using namespace std;

int main(void)
{

	string str, ret;
	int n;

	FAST_IO;

	ret.push_back('A');
	ret.push_back('B');

	cin >> n;
	while (n--)
	{

		cin >> str;
		ret[0] = str[0];
		ret[1] = str.back();

		cout << ret << endl;
	}

	return 0;
}
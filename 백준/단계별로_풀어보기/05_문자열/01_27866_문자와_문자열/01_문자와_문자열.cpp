/*
날짜 : 2024. 8. 6
이름 : 배성훈
내용 : 문자와 문자열
	문제번호 : 27866번

	구현, 문자열 문제다
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);	\
				cout.tie(NULL);	\
				ios_base::sync_with_stdio(false);

using namespace std;

int main(void)
{

	string str;
	int idx;
	FAST_IO;

	cin >> str >> idx;

	cout << str[idx - 1];
	return 0;
}
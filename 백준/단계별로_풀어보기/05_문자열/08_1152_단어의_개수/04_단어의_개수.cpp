/*
날짜 : 2024. 8. 7
이름 : 배성훈
내용 : 단어의 개수
	문제번호 : 1152번

	구현, 문자열 문제다
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

	while (cin >> str)
	{

		ret++;
	}

	cout << ret;
	return 0;
}
/*
날짜 : 2024. 8. 8
이름 : 배성훈
내용 : 그대로 출력하기
	문제번호 : 11718번

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

	string str;
	int c;
	while (cin)
	{

		c = cin.get();

		if (c == '\r') continue;
		else if (c == '\n')
		{

			cout << str << endl;
			str.clear();
			continue;
		}

		str.push_back(c);
	}

	return 0;
}
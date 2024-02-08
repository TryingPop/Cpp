#include <iostream>
#include <string>

/*
날짜 : 2024. 2. 8
이름 : 배성훈
내용 : 문자열 돌리기
	주어진 문자열을 하나씩 읽기
*/

using namespace std;

int main3(void)
{

	string str;
	cin >> str;


	for (const char c: str)
	// for (int i = 0; i < str.length(); i++)
	{

		// cout << str[i] << '\n';
		cout << c << '\n';
	}
	return 0;
}
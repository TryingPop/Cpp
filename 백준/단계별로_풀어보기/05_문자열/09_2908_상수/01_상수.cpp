/*
날짜 : 2024. 8. 8
이름 : 배성훈
내용 : 상수
	문제번호 : 2908번

	수학, 구현 문제다
*/

#include <iostream>
#include <string>

using namespace std;

inline int RevStrToInt(string _str)
{

	int ret = 0;
	for (int i = _str.length() - 1; i >= 0; i--) 
	{

		ret = ret * 10 + _str[i] - '0';
	}

	return ret;
}

int main(void)
{

	string str;
	int a, b;

	cin >> str;
	a = RevStrToInt(str);
	cin >> str;
	b = RevStrToInt(str);
	
	cout << (a < b ? b : a);

	return 0;
}
#include <iostream>
#include <string>

/*
날짜 : 2024. 2. 7
이름 : 배성훈
내용 : 대소문자 바꿔서 출력하기
	문자열을 입력 받으면 대소문자 바꿔서 출력하기
*/

using namespace std;

int main4(void)
{

	string str;
	cin >> str;

	char diff = 'a' - 'A';

	for (int i = 0; i < str.length(); i++) 
	{

		if (str[i] >= 'a') str[i] -= diff;
		else str[i] += diff;
	}

	cout << str;
	return 0;
}
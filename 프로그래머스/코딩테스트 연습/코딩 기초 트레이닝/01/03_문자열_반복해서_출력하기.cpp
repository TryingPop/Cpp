#include <iostream>
#include <string>

/*
날짜 : 2024. 2. 7
이름 : 배성훈
내용 : 문자열 반복해서 출력하기
	문자열과 숫자를 입력받으면 해당 문자열을 숫자만큼 이어붙인다
*/

using namespace std;

int main3(void)
{

	string str;
	int n;

	cin >> str >> n;
	for (int i = 0; i < n; i++) 
	{

		cout << str;
	}

	return 0;
}
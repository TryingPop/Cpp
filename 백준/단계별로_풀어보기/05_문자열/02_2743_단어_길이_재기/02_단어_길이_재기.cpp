/*
날짜 : 2024. 8. 6
이름 : 배성훈
내용 : 단어 길이 재기
	문제번호 : 2743번
*/

#include <iostream>
#include <string>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	string str;
	FAST_IO;

	cin >> str;
	cout << str.length();

	return 0;
}
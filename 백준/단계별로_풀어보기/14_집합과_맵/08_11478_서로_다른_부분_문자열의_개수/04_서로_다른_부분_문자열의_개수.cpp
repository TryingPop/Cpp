/*
날짜 : 2024. 8. 28
이름 : 배성훈
내용 : 서로 다른 부분 문자열의 개수
	문제번호 : 11478번

	자료구조, 문자열, 해시 문제다
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{

	unordered_set<string> chk;
	string str, sub;
	int ret = 0;

	cin >> str;

	for (int i = 1; i <= str.length(); i++)
	{

		for (int j = 0; j <= str.length() - i; j++)
		{

			sub = str.substr(j, i);
			if (chk.count(sub)) continue;
			ret++;
			chk.insert(sub);
		}
	}

	cout << ret;
	return 0;
}
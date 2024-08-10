/*
날짜 : 2024. 8. 10
이름 : 배성훈
내용 : 단어 공부
	문제번호 : 1157번

	구현, 문자열 문제다
*/

#include <iostream>
#include <string>
#include <vector>

#define FAST_IO	cin.tie(NULL);		\
				cout.tie(NULL);		\
				ios_base::sync_with_stdio(false)

using namespace std;

int main(void)
{

	string str;
	vector<int> use(26, 0);

	FAST_IO;
	cin >> str;

	for (const char c : str)
	{

		if ('A' <= c && c <= 'Z') use[c - 'A']++;
		else use[c - 'a']++;
	}

	int max = -1;
	char ret = '?';
	for (int i = 0; i < 26; i++)
	{

		if (max < use[i])
		{

			ret = i + 'A';
			max = use[i];
		}
		else if (max == use[i]) ret = '?';
	}

	cout << ret;

	return 0;
}
#include <string>
#include <vector>

/*
날짜 : 2024. 3. 20
이름 : 배성훈
내용 : 문자열 정렬하기 2
	영어 대소문자로 이루어진 문자열 my_string이
	매개변수로 주어질 때,
	my_string을 모두 소문자로 바꾸고
	알파벳 순서대로 정렬한 문자열을
	return하는 solution 함수 구현
*/

using namespace std;

string solution(string _my_string)
{

	string answer;
	answer.reserve(_my_string.length());

	vector<int> cnt(26, 0);
	for (const char c : _my_string)
	{

		int idx;
		if ('Z' < c) idx = c - 'a';
		else idx = c - 'A';

		cnt[idx]++;
	}

	for (int i = 0; i < 26; i++)
	{

		char c = i + 'a';
		for (int j = 0; j < cnt[i]; j++)
		{

			answer.push_back(c);
		}
	}

	return answer;
}
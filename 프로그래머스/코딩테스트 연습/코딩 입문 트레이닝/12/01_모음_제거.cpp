#include <string>

/*
날짜 : 2024. 3. 14
이름 : 배성훈
내용 : 모음 제거
	문자열 my_string이 주어질 때,
	my_string에서
	a, e, i, o, u를 제거한
	문자열을 return하는 solution 함수 구현

	my_string은 알파벳 소문자와 공백으로
	이루어진 문자열이다
*/

using namespace std;

string solution(string _my_string)
{

	string answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string) 
	{

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;

		answer.push_back(c);
	}

	return answer;
}
#include <string>

/*
날짜 : 2024. 3. 16
이름 : 배성훈
내용 : 대문자와 소문자
	문자열 my_string이 매개변수로 주어질 때,
	대문자는 소문자로, 소문자는 대문자로 변환한
	문자열을 return 하도록 solution 함수를 구현

	my_string은 알파벳 대문자와 소문자로만 
	구성되어 있다
*/

using namespace std;

string solution(string _my_string)
{

	string answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string)
	{

		if (c >= 'a') answer.push_back(c - 'a' + 'A');
		else answer.push_back(c - 'A' + 'a');
	}

	return answer;
}
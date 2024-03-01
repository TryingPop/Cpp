#include <string>

/*
날짜 : 2024. 3. 1
이름 : 배성훈
내용 : l로 바꾸기
	알파벳 소문자로 이루어진 문자열 myString
	알파벳 순서에서 l보다 앞서는 모든 문자를
	l로 바꾼 문자열을 return하는 solution 함수 구현
*/

using namespace std;

string solution(string _myString)
{

	string answer = "";
	answer.reserve(_myString.length());

	for (const char c : _myString)
	{

		if (c < 'l') answer.push_back('l');
		else answer.push_back(c);
	}

	return answer;
}
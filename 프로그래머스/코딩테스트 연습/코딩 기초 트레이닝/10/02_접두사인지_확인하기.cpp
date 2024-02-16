#include <string>

/*
날짜 : 2024. 2. 16
이름 : 배성훈
내용 : 접두사인지 확인하기
	banana의 접두사는 
		b
		ba
		ban
		bana
		banan
		banana

	문자열 my_string과 is_prefix가 주어질 때, is_prefix가 my_string의 접두사라면 
	1을 아니면 0을 반환하는 함수 구현
*/

using namespace std;

int solution(string _my_string, string _is_prefix)
{

	int answer;

	if (_my_string.length() < _is_prefix.length()) answer = 0;
	else answer = _my_string.substr(0, _is_prefix.length()) == _is_prefix;

	return answer;
}
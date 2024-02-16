#include <string>
// #include <vector>
// #include <algorithm>

/*
날짜 : 2024. 2. 16
이름 : 배성훈
내용 : 문자열 뒤집기
	문자열 my_string과 정수 s, e가 매개변수로 주어질 때,
	my_string에서 인덱스 s부터 인덱스 e까지를 뒤집은 문자열을
	return 하는 solution 함수 작성하기
*/

using namespace std;

string solution(string _my_string, int _s, int _e)
{

	string answer;
	answer.reserve(_my_string.length());
	
	for (int i = 0; i < _s; i++)
	{

		answer.push_back(_my_string[i]);
	}

	for (int i = _e; i >= _s; i--)
	{

		answer.push_back(_my_string[i]);
	}

	for (int i = _e + 1; i < _my_string.length(); i++)
	{

		answer.push_back(_my_string[i]);
	}

	// for (int i = _s, int j = _e; i < j; i++, j--) { }
	// reverse(answer.begin() + _s, answer.begin() + _e + 1);
	return answer;
}
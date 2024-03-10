#include <string>

/*
날짜 : 2024. 3. 10
이름 : 배성훈
내용 : 특정 문자 제거하기
	문자열 my_string과 문자 letter이 매개변수로 주어진다
	my_string에서 letter를 제거한 문자열을
	return 하는 solution 함수 구현

	letter은 길이가 1인 영문자이고
	대소문자를 구분한다
*/

using namespace std;

string solution(string _my_string, string _letter)
{

	string answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string)
	{

		if (c == _letter[0]) continue;
		answer.push_back(c);
	}

	return answer;
}
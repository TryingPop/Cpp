#include <string>

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 문자 반복 출력하기
	문자열 my_string과 정수 n이 매개변수로 주어질 때,
	my_string에 들어있는 각 문자를 n만큼 반복한 문자열을
	return 하도록 solution 함수를 구현
*/

using namespace std;

string solution(string _my_string, int _n)
{

	string answer;
	answer.reserve(_my_string.length() * _n);

	for (const char c : _my_string)
	{

		for (int i = 0; i < _n; i++)
		{

			answer.push_back(c);
		}
	}

	return answer;
}
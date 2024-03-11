#include <string>

/*
날짜 : 2024. 3. 11
이름 : 배성훈
내용 : 가위 바위 보
	가위는 2, 바위는 0, 보는 5로 표현된다
	가위 바위 보를 순서대로 나타낸 문자열 rsp가 매개변수로 주어질 때,
	rsp에 저장된 가위 바위 보를 모두 이기는 경우를 순서대로 나타낸
	문자열을 return 하는 solution 함수 구현
*/

using namespace std;

string solution(string _rsp)
{

	string answer;
	answer.reserve(_rsp.length());

	for (const char c : _rsp)
	{

		if (c == '2') answer.push_back('0');
		else if (c == '0') answer.push_back('5');
		else answer.push_back('2');
	}

	return answer;
}
#include <string>

/*
날짜 : 2024. 2. 10
이름 : 배성훈
내용 : 조건 문자열
	문자열에 따라 두 수의 크기를 비교
	ineq 는 '<', '>' 중 하나
	eq는 '=' 와 '!'중 하나

	ineq와 eq를 이어 붙였을 때, <=, >=는 그대로 의미이고 <!는 >! 는 <, > 연산을 의미
	n, m 이 ineq와 eq에 맞으면 1 아니면 0을 리턴
*/

using namespace std;

int solution(string _ineq, string _eq, int _n, int _m)
{

	int answer = 0;

	if (_ineq == "<") 
	{

		if (_eq == "=") answer = _n <= _m;
		else answer = _n < _m;
	}
	else 
	{

		if (_eq == "=") answer = _n >= _m;
		else answer = _n > _m;
	}
	return answer;
}
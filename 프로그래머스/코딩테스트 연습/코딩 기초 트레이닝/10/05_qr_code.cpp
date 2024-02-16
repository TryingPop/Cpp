#include <string>

/*
날짜 : 2024. 2. 16
이름 : 배성훈
내용 : qr code
	두 정수 q, r과 문자열 code가 주어질 때,
	code의 각 인덱스를 q로 나누었을 때 나머지가 r인
	위치의 문자를 앞에서부터 순서대로 이어 붙인 문자열을 return하는 solution 함수 구현
*/
using namespace std;

string solution(int _q, int _r, string _code) 
{

	string answer;

	for (int i = _r; i < _code.length(); i += _q)
	{

		answer.push_back(_code[i]);
	}
	return answer;
}
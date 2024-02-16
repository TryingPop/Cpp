#include <string>

/*
날짜 : 2024. 2. 16
이름 : 배성훈
내용 : 세로 읽기
	문자열 my_string과 두 정수 m, c가 주어진다
	my_string을 한 줄에 m 글자씩 가로로 적었을 때,
	왼쪽부터 세로로 c번째 열에 적힌 글자들을 문자열로 return 하는 solution 함수 구현
*/
using namespace std;

string solution(string _my_string, int _m, int _c)
{

	string answer;

	for (int i = _c - 1; i < _my_string.length(); i += _m) 
	{

		answer.push_back(_my_string[i]);
	}
	return answer;
}
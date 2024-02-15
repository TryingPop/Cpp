#include <string>

/*
날짜 : 2024. 2. 15
이름 : 배성훈
내용 : 문자열의 뒤의 n글자
	문자열 my_string과 정수 n이 매개변수로 주어질 때,
	my_string의 뒤의 n글자로 이루어진 문자열을 return하는 solution 함수를 구현
*/

using namespace std;

string solution(string _my_string, int _n)
{

	string answer;
	int len = _my_string.length();
	// len - _n 번부터 끝까지 자른 문자열을 반환
	answer = _my_string.substr(len - _n);
	return answer;
}
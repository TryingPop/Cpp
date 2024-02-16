#include <string>

/*
날짜 : 2024. 2. 16
이름 : 배성훈
내용 : 문자열의 앞의 n글자
	문자열 my_string과 정수 n이 매개변수로 주어질 때,
	my_string의 앞의 n글자로 이루어진 문자열을 return하는 solution 함수를 작성
*/

using namespace std;

string solution(string _my_string, int _n) 
{

	string answer;

	answer = _my_string.substr(0, _n);
	// answer = string(_my_string.begin(), _my_string.begin() + _n);
	// answer.assign(_my_string.begin(), _my_string.begin() + _n);
	return answer;
}
#include <string>

/*
날짜 : 2024. 2. 28
이름 : 배성훈
내용 : 부분 문자열인지 확인하기
	문자열 my_string과 target이 매개변수로 주어질 때,
	target이 문자열 my_string의 부분 문자열이라면 1을,
	아니라면 0을 return 하는 solution 함수를 구현
*/

using namespace std;

int solution(string _my_string, string _target)
{

	int answer;

	answer = _my_string.find(_target) != string::npos;
	return answer;
}
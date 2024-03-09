#include <string>
#include <algorithm>

/*
날짜 : 2024. 3. 9
이름 : 배성훈
내용 : 문자열 뒤집기
	문자열 my_string이 매개변수로 주어질 때,
	my_string을 거꾸로 뒤집은 문자열을
	return 하는 solution 함수를 구현
*/

using namespace std;

string solution(string _my_string)
{

	string answer = _my_string;
	
	reverse(_my_string.begin(), _my_string.end());
	return answer;
}
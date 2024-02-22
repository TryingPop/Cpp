#include <string>
#include <algorithm>

/*
날짜 : 2024. 2. 22
이름 : 배성훈
내용 : 소문자로 바꾸기
	알파벳으로 이루어진 문자열 myString
	모든 알파벳을 소문자로 변환하여 return하는 solution 함수 구현
*/

using namespace std;

string solution(string _myString)
{

	string answer;

	answer = _myString;

	transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	return answer;
}
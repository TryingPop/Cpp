#include <string>

/*
날짜 : 2024. 2. 29
이름 : 배성훈
내용 : 부분 문자열
	문자열 str1, str2가 주어진다
	str1이 str2의 부분 문자열이라면 1을
	부분 문자열이 아니라면 0을
	return 하는 solution 함수를 구현

	여기서 말하는 부분 문자열이란
	a가 b의 부분문자열이라면 b = ? + a + ?
	의 형태로 표현 가능
*/

using namespace std;

int solution(string _str1, string _str2)
{

	int answer = _str2.find(_str1) != string::npos;

	return answer;
}
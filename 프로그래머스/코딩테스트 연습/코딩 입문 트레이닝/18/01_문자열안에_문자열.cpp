#include<string>

/*
날짜 : 2024. 3. 20
이름 : 배성훈
내용 : 문자열안에 문자열
	문자열 str1, str2가 매개변수로 주어질 때,
	str1 안에 str2가 있다면 1을 없다면 2를
	return 하는 solution 함수 구현
*/

using namespace std;

int solution(string _str1, string _str2) 
{

	int answer = 0;
	answer = _str1.find(_str2) != string::npos ? 1 : 2;
	return answer;
}
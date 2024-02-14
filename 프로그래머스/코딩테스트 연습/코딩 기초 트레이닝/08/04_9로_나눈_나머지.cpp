#include <string>

/*
날짜 : 2024. 2. 14
이름 : 배성훈
내용 : 9로 나눈 나머지
	음이 아닌 정수를 9로 나눈 나머지는 각 자리 숫자의 합을 9로 나눈 나머지와 일치한다
	이를 이용해 음이 아닌 정수가 문자열 number로 주어질 때, 이 정수를 9로 나눈 나머지를
	return 하는 함수 만들기
*/

using namespace std;

int solution(string _number)
{

	int answer = 0;

	for (const char c : _number) 
	{

		answer += c - '0';
		answer = 8 < answer ? answer - 9 : answer;
	}

	return answer;
}
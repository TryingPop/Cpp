#include <string>

/*
날짜 : 2024. 2. 27
이름 : 배성훈
내용 : 문자열 정수의 합
	한 자리 정수로 이루어진 문자열
	num_str이 주어진다

	각 자리수의 합을 retun 하도록 solution 함수를 구현
*/

using namespace std;

int solution(string _num_str)
{

	int answer = 0;

	for (const char c : _num_str)
	{

		answer += c - '0';
	}

	return answer;
}
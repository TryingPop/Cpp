#include <string>

/*
날짜 : 2024. 3. 14
이름 : 배성훈
내용 : 숨어있는 숫자의 덧셈 1
	문자열 my_string이 매개변수로 주어질 때,
	my_string 안의 모든 자연수들의 합을
	return 하는 solution 함수 구현
*/

using namespace std;

int solution(string _my_string)
{

	int answer = 0;

	for (const char c : _my_string)
	{

		if (c < '0' || c > '9') continue;
		answer += c - '0';
	}

	return answer;
}
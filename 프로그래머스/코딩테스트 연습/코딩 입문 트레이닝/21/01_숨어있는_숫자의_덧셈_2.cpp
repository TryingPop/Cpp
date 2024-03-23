#include <string>

/*
날짜 : 2024. 3. 23
이름 : 배성훈
내용 : 숨어 있는 숫자의 덧셈_2
	문자열 my_string이 매개변수로 주어진다
	my_string은 소문자, 대문자, 자연수로만
	구성되어 있다

	my_string 안의 자연수들의 합을 
	return 하도록 solution 함수를 완성
*/

using namespace std;

int solution(string _my_string)
{

	int answer = 0;
	int num = 0;

	for (const char c : _my_string)
	{

		if (c < '0' || '9' < c) 
		{

			// 숫자 아닌 문자가 온 경우
			answer += num;
			num = 0;
			continue;
		}

		// 숫자 연달아 입력 받은 경우
		num = 10 * num + c - '0';
	}

	// 남아 있는 숫자
	if (num) answer += num;
	return answer;
}
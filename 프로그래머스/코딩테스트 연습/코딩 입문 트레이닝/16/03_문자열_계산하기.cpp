#include <string>

/*
날짜 : 2024. 3. 18
이름 : 배성훈
내용 : 문자열 계산하기
	my_string은 3 + 5 처럼 문자열로 된 수식
	문자열 my_string이 매개변수로 주어질 때,
	수식을 계산한 값을 return 하는 solution 함수를 구현

	연산자는 +와 -만 주어진다
	0으로 시작하는 숫자는 주어지지 않는다
	시작과 끝에 공백은 주어지지 않는다
	my_string을 계산한 결과는 절대값 10만 이하
	중간 계산값도 절대값 10만 이하
	my_string에 적어도 하나의 연산자가 포함
	숫자와 연산자는 1개의 공백으로 구분
*/

using namespace std;

int solution(string _my_string)
{

	int answer = 0;

	int calc = 0;
	bool isDigit = true;
	bool plus = true;

	for (const char c : _my_string)
	{

		if (c == ' ')
		{

			if (isDigit)
			{

				isDigit = false;
				answer += plus ? calc : -calc;
				calc = 0;
			}
			else isDigit = true;
		}
		else if (c == '+') plus = true;
		else if (c == '-') plus = false;
		else calc = calc * 10 + c - '0';
	}

	if (calc != 0) answer += plus ? calc : -calc;
	
	return answer;
}
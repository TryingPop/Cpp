#include <string>
#include <vector>

/*
날짜 : 2024. 2. 24
이름 : 배성훈
내용 : 간단한 식 계산하기
	문자열 binomial이 매개변수로 주어진다
	binomial은 "a op b" 형태의 이항식이고
	a와 b는 음이 아닌 정수,
	op는 '+', '-', '*' 중 하나
	주어진 식을 계산한 정수를 
	return하는 solution 함수 작성
*/

using namespace std;

int solution(string _binomial)
{

	int answer = 0;

	int idx = 0;
	int op = -1;

	for (int i = 0; i < _binomial.length(); i++) 
	{

		char cur = _binomial[i];

		if (cur == '+')
		{

			idx = i;
			op = 1;
			break;
		}
		else if (cur == '-')
		{

			idx = i;
			op = 2;
			break;
		}
		else if (cur == '*')
		{

			idx = i;
			op = 3;
			break;
		}
	}

	int a = stoi(_binomial.substr(0, idx - 1));
	int b = stoi(_binomial.substr(idx + 2));

	if (op == 1) answer = a + b;
	else if (op == 2) answer = a - b;
	else if (op == 3) answer = a * b;

	return answer;
}
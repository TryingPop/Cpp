/*
날짜 : 2024. 6. 9
이름 : 배성훈
내용 : 올바른 괄호
	괄호가 바르게 짝지어졌다는 것은 '('문자로 열렸으면
	반드시 짝지어서 ')'문자로 닫혀야한다는 뜻이다

	예를들어 "()()" 또는 "(())()"는 올바른 괄호이다
	반면 ")()(" 또는 "(()("는 올바른 괄호가 아니다

	'(' 또는 ')'로만 이루어진 문자열 s가 주어졌을 때,
	문자열 s가 올바른 괄호이면 true를 return하고,

	올바르지 않은 괄호이면 false를 return 하는
	solution 함수를 구현

	문자열 길이는 10만 이하의 자연수
	문자열 s는 '(' 또는 ')'로만 이루어져 있다
*/

#include <string>
#include <vector>

using namespace std;

bool solution(string _s)
{

	bool answer = true;

	vector<char> stack;
	stack.reserve(_s.length());

	for (const char c : _s)
	{

		if (c == '(')
		{

			stack.push_back(c);
			continue;
		}

		if (stack.empty())
		{

			answer = false;
			break;
		}

		stack.pop_back();
	}

	if (!stack.empty()) answer = false;

	return answer;
}
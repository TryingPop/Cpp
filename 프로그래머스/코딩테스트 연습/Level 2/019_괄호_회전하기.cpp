/*
날짜 : 2024. 6. 26
이름 : 배성훈
내용 : 괄호 회전하기
	(), [], {} 는 모두 올바른 괄호 문자열이다
	만약 A가 올바른 괄호문자열이면, (A), {A}, [A]도 올바른 괄호문자열이다
	그리고 A, B가 올바른 괄호 문자열이면 AB도 올바른 괄호 문자열이다

	대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어질 때,
	이 s를 왼쪽으로 0<= x < s.length() 만큼 회전시켰을 때,
	s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하는 solution 함수 구현

	parameter
	"[](){}"


	return
	3


	sol
	0칸 회전 [](){} -> O
	1칸 회전 ](){}[ -> X
	2칸 회전 (){}[] -> O
	3칸 회전 ){}[]( -> X
	4칸 회전 {}[]() -> O
	5칸 회전 }[](){ -> X
*/

#include <string>
#include <vector>

using namespace std;

inline bool ChkRight(int _chk)
{

	return _chk == ')' || _chk == '}' || _chk == ']';
}

inline bool ChkMatch(vector<int>& _stack, int _chk)
{

	switch (_chk)
	{

	case ')':
		return _stack.back() == '(';

	case '}':
		return _stack.back() == '{';

	case ']':
		return _stack.back() == '[';
	}

	return false;
}

inline bool ChkCorrect(string& _s, vector<int>& _stack, int _start, int _len)
{

	_stack.clear();

	for (int i = _start; i < _start + _len; i++)
	{

		int cur = _s[i];
		if (_stack.size() == 0)
		{

			if (ChkRight(cur))
			{

				_stack.push_back(0);
				break;
			}
			else 
			{

				_stack.push_back(cur);
				continue;
			}
		}

		if (ChkRight(cur))
		{

			if (ChkMatch(_stack, cur)) _stack.pop_back();
			else
			{

				_stack.push_back(0);
				break;
			}
		}
		else _stack.push_back(cur);
	}

	return _stack.empty();
}


int solution(string _s)
{

	int answer = 0;
	int len = _s.length();

	_s += _s;
	vector<int> stack;
	stack.reserve(len);
	for (int i = 0; i < len; i++)
	{

		if (ChkCorrect(_s, stack, i, len)) answer++;
	}

	return answer;
}
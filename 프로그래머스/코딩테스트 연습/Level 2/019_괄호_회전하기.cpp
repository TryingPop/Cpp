/*
��¥ : 2024. 6. 26
�̸� : �輺��
���� : ��ȣ ȸ���ϱ�
	(), [], {} �� ��� �ùٸ� ��ȣ ���ڿ��̴�
	���� A�� �ùٸ� ��ȣ���ڿ��̸�, (A), {A}, [A]�� �ùٸ� ��ȣ���ڿ��̴�
	�׸��� A, B�� �ùٸ� ��ȣ ���ڿ��̸� AB�� �ùٸ� ��ȣ ���ڿ��̴�

	���ȣ, �߰�ȣ, �׸��� �Ұ�ȣ�� �̷���� ���ڿ� s�� �Ű������� �־��� ��,
	�� s�� �������� 0<= x < s.length() ��ŭ ȸ�������� ��,
	s�� �ùٸ� ��ȣ ���ڿ��� �ǰ� �ϴ� x�� ������ return �ϴ� solution �Լ� ����

	parameter
	"[](){}"


	return
	3


	sol
	0ĭ ȸ�� [](){} -> O
	1ĭ ȸ�� ](){}[ -> X
	2ĭ ȸ�� (){}[] -> O
	3ĭ ȸ�� ){}[]( -> X
	4ĭ ȸ�� {}[]() -> O
	5ĭ ȸ�� }[](){ -> X
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
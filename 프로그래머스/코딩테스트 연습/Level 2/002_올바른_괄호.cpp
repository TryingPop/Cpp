/*
��¥ : 2024. 6. 9
�̸� : �輺��
���� : �ùٸ� ��ȣ
	��ȣ�� �ٸ��� ¦�������ٴ� ���� '('���ڷ� ��������
	�ݵ�� ¦��� ')'���ڷ� �������Ѵٴ� ���̴�

	������� "()()" �Ǵ� "(())()"�� �ùٸ� ��ȣ�̴�
	�ݸ� ")()(" �Ǵ� "(()("�� �ùٸ� ��ȣ�� �ƴϴ�

	'(' �Ǵ� ')'�θ� �̷���� ���ڿ� s�� �־����� ��,
	���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return�ϰ�,

	�ùٸ��� ���� ��ȣ�̸� false�� return �ϴ�
	solution �Լ��� ����

	���ڿ� ���̴� 10�� ������ �ڿ���
	���ڿ� s�� '(' �Ǵ� ')'�θ� �̷���� �ִ�
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
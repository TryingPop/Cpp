/*
��¥ : 2024. 8. 2
�̸� : �輺��
���� : ū �� �����
	� ���ڿ��� k���� ���� �������� ��
	���� �� �ִ� ���� ū ���ڸ� ���Ϸ��� �Ѵ�

	���ڿ� �������� ���� number�� ������ ���� ���� k��
	solution �Լ��� �Ű������� �־��� ��,

	number���� k���� ���� �������� �� ���� �� �ִ�
	�� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ���
	solution �Լ��� ����

	number�� 2�ڸ� �̻� 100�� �ڸ� ������ �����̰�,
	k�� 1�̻� number�� �ڸ��� �̸��� �ڿ����̴�

	parameter
	"1231234", 3


	return
	"3234"


	sol
	12, 1�� �����ϸ�ȴ�
*/

#include <string>

using namespace std;

string solution(string _number, int _k)
{

	/*
	
	����, Greedy

	*/
	string answer = "";
	answer.reserve(_number.size() - _k + 1);

	// �տ������� ���� ����Ƚ���Ÿ� �ȿ� 
	// �ڱ⺸�� �ڿ� ū ���� ������ �����Ѵ�
	// �ƴϸ� �ش� ���� �츰��
	int top = -1;
	for (const char c : _number)
	{

		while (_k > 0 && top >= 0 && _number[top] < c)
		{

			top--;
			_k--;
		}

		_number[++top] = c;
	}

	// ���� k�� ���� �ȵǸ� �ڿ������� �����Ѵ�
	if (_k) top -= _k;

	// ���� �̾���̱�
	answer.insert(answer.begin(), _number.begin(), _number.begin() + top + 1);

	return answer;
}
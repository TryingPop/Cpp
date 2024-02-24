#include <string>
#include <vector>

/*
��¥ : 2024. 2. 24
�̸� : �輺��
���� : ������ �� ����ϱ�
	���ڿ� binomial�� �Ű������� �־�����
	binomial�� "a op b" ������ ���׽��̰�
	a�� b�� ���� �ƴ� ����,
	op�� '+', '-', '*' �� �ϳ�
	�־��� ���� ����� ������ 
	return�ϴ� solution �Լ� �ۼ�
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
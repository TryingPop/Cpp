#include <string>
#include <vector>

/*
��¥ : 2024. 2. 11
�̸� : �輺��
���� : �ڵ� ó���ϱ�
	���ڿ� code�� �Է¹޴´�
	���ڿ��� �ϳ��� �о�µ�, 
	
	��忡 ���� ���ڿ��� ��ȯ�Ѵ�
	���� 2������ �ִ�

	��� 0 : ���ڿ��� ¦�� �κи� ���
	��� 1 : ���ڿ��� Ȧ�� �κи� ���

	�ʱ� ���� 0�̸�, ���ڿ��� �ϳ��� �о���µ� "1"�� �д� ���� ��带 �����Ѵ�
	�׸��� �� �о��� ��, ���ڿ��� ���̰� 0�̸�, EMPTY�� ��ȯ�ϴ� ����

	length() == 0�� �ƴ� empty �޼��带 �̿��� �Ǻ� �����ϴ�
*/

using namespace std;

string solution(string _code) 
{

	string answer;

	answer.reserve(_code.size() / 2);
	int mode = 0;
	
	for (int i = 0; i < _code.length(); i++)
	{

		const char c = _code[i];
		if (c == '1') 
		{ 
			
			mode = mode ? 0 : 1; 
			continue;
		}

		if ((i & 1) == mode) answer.push_back(c);
	}

	if (answer.empty()) answer = "EMPTY";
	return answer;
}
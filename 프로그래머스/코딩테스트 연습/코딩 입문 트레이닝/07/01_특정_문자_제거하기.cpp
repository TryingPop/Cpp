#include <string>

/*
��¥ : 2024. 3. 10
�̸� : �輺��
���� : Ư�� ���� �����ϱ�
	���ڿ� my_string�� ���� letter�� �Ű������� �־�����
	my_string���� letter�� ������ ���ڿ���
	return �ϴ� solution �Լ� ����

	letter�� ���̰� 1�� �������̰�
	��ҹ��ڸ� �����Ѵ�
*/

using namespace std;

string solution(string _my_string, string _letter)
{

	string answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string)
	{

		if (c == _letter[0]) continue;
		answer.push_back(c);
	}

	return answer;
}
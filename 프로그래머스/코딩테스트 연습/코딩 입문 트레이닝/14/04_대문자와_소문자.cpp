#include <string>

/*
��¥ : 2024. 3. 16
�̸� : �輺��
���� : �빮�ڿ� �ҹ���
	���ڿ� my_string�� �Ű������� �־��� ��,
	�빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� ��ȯ��
	���ڿ��� return �ϵ��� solution �Լ��� ����

	my_string�� ���ĺ� �빮�ڿ� �ҹ��ڷθ� 
	�����Ǿ� �ִ�
*/

using namespace std;

string solution(string _my_string)
{

	string answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string)
	{

		if (c >= 'a') answer.push_back(c - 'a' + 'A');
		else answer.push_back(c - 'A' + 'a');
	}

	return answer;
}
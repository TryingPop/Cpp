#include <string>

/*
��¥ : 2024. 3. 14
�̸� : �輺��
���� : ���� ����
	���ڿ� my_string�� �־��� ��,
	my_string����
	a, e, i, o, u�� ������
	���ڿ��� return�ϴ� solution �Լ� ����

	my_string�� ���ĺ� �ҹ��ڿ� ��������
	�̷���� ���ڿ��̴�
*/

using namespace std;

string solution(string _my_string)
{

	string answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string) 
	{

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;

		answer.push_back(c);
	}

	return answer;
}
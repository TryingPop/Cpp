#include <string>

/*
��¥ : 2024. 3. 9
�̸� : �輺��
���� : ���� �ݺ� ����ϱ�
	���ڿ� my_string�� ���� n�� �Ű������� �־��� ��,
	my_string�� ����ִ� �� ���ڸ� n��ŭ �ݺ��� ���ڿ���
	return �ϵ��� solution �Լ��� ����
*/

using namespace std;

string solution(string _my_string, int _n)
{

	string answer;
	answer.reserve(_my_string.length() * _n);

	for (const char c : _my_string)
	{

		for (int i = 0; i < _n; i++)
		{

			answer.push_back(c);
		}
	}

	return answer;
}
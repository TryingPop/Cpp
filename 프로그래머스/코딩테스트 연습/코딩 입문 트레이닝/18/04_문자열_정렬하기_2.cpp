#include <string>
#include <vector>

/*
��¥ : 2024. 3. 20
�̸� : �輺��
���� : ���ڿ� �����ϱ� 2
	���� ��ҹ��ڷ� �̷���� ���ڿ� my_string��
	�Ű������� �־��� ��,
	my_string�� ��� �ҹ��ڷ� �ٲٰ�
	���ĺ� ������� ������ ���ڿ���
	return�ϴ� solution �Լ� ����
*/

using namespace std;

string solution(string _my_string)
{

	string answer;
	answer.reserve(_my_string.length());

	vector<int> cnt(26, 0);
	for (const char c : _my_string)
	{

		int idx;
		if ('Z' < c) idx = c - 'a';
		else idx = c - 'A';

		cnt[idx]++;
	}

	for (int i = 0; i < 26; i++)
	{

		char c = i + 'a';
		for (int j = 0; j < cnt[i]; j++)
		{

			answer.push_back(c);
		}
	}

	return answer;
}
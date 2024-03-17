#include <string>
#include <vector>

/*
��¥ : 2024. 3. 17
�̸� : �輺��
���� : �� ���� ������ ����
	���ڿ� s�� �Ű������� �־��� ��,
	s���� �� ���� �����ϴ� ���ڸ�
	���� ������ ������ ���ڿ���
	return �ϴ� solution �Լ� ����

	�� ���� �����ϴ� ���ڰ� ���� ���
	�� ���ڿ��� return

	s�� �ҹ��ڷθ� �̷���� �ִ�
*/

using namespace std;

string solution(string _s)
{

	string answer = "";
	answer.reserve(_s.length());

	vector<int> cnt(26, 0);

	for (const char c : _s)
	{

		// ���� ���� ����
		cnt[c - 'a']++;
	}

	for (int i = 0; i < cnt.size(); i++)
	{

		// �� ���� ���ڸ� �̾� ���δ�
		if (cnt[i] == 1) answer.push_back(i + 'a');
	}

	return answer;
}
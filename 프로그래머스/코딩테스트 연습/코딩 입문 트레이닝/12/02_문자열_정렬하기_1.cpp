#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 3. 14
�̸� : �輺��
���� : ���ڿ� �����ϱ� 1
	���ڿ� my_string�� �Ű������� �־��� ��,
	my_string �ȿ� �ִ� ���ڸ� ���
	������������ ������ ����Ʈ��
	return �ϴ� solution �Լ� ����

	my_string���� ��� 
	�ϳ��� ���ڰ� ���ԵǾ��� �ִ�
*/

using namespace std;

vector<int> solution(string _my_string)
{

	vector<int> answer;
	answer.reserve(_my_string.length());

	for (const char c : _my_string)
	{

		if (c < '0' || c > '9') continue;
		answer.push_back(c - '0');
	}

	sort(answer.begin(), answer.end());

	return answer;
}
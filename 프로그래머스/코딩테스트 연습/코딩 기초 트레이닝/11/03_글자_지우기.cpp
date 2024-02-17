#include <string>
#include <vector>
#include <algorithm>

/*
��¥ : 2024. 2. 17
�̸� : �輺��
���� : ���� �����
	���ڿ� my_string�� �����迭 indices�� �־��� ��,
	my_string���� indices�� ���ҿ� �ش��ϴ� �ε����� ���ڸ� �����
	�̾� ���� ���ڿ��� return�ϴ� solution �Լ��� �ۼ�

	my_string�� ��ҹ��� ���ĺ����θ� �̷���� �ִ�!
*/

using namespace std;

string solution(string _my_string, vector<int> _indices)
{

	string answer;

#if Slow
	answer = _my_string;

	// ���� ���� ����
	sort(_indices.begin(), _indices.end(), greater<int>());

	// �ڿ������� �ϳ��� ����
	for (const int indice : _indices)
	{

		answer.erase(indice);
	}
#else

	string temp = _my_string;
	answer.reserve(_my_string.length() - _indices.size());

	for (const int indice : _indices)
	{

		temp[indice] = ' ';
	}

	for (const char c : temp)
	{

		if (c == ' ') continue;
		answer.push_back(c);
	}
#endif
	return answer;
}
#include <string>
#include <vector>

/*
��¥ : 2024. 3. 21
�̸� : �輺��
���� : �߶� �迭�� �����ϱ�
	���ڿ� my_str�� n�� �Ű������� �־��� ��,
	my_str�� ���� n�� �߶� ������ �迭��
	return �ϵ��� solution �Լ��� ����
*/

using namespace std;

vector<string> solution(string _my_str, int _n)
{

	vector<string> answer;

	int len = _my_str.length() / _n;
	if (_my_str.length() % _n) len++;
	answer.reserve(len);

	string temp;
	temp.reserve(_n);

	for (const char c : _my_str) 
	{

		temp.push_back(c);
		if (temp.length() != _n) continue;

		answer.push_back(temp);
		temp.clear();
	}

	if (!temp.empty()) answer.push_back(temp);
	return answer;
}